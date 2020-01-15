import { DataStore } from "/js/base/DataStore.js";
import { UpPencil } from "./runtime/UpPencil.js";
import { DownPencil } from "./runtime/DownPencil.js";
//import { Pencil } from './js/runtime/Pencil.js';

export class Director {

    static getInstance() {
        if (!Director.instance) {
            Director.instance = new Director();
        }
        return Director.instance;
    }
    constructor() {
        this.dataStore = DataStore.getInstance();
        this.velocity=0;
    }

    createPencil() {
        const minTop = window.innerHeight / 8;
        const maxTop = window.innerHeight / 2;

        const top = minTop + (maxTop - minTop) * Math.random();

        this.dataStore.get('pencils').push(new UpPencil(top));
        this.dataStore.get('pencils').push(new DownPencil(top));
    }

    run() {
        //      console.log(this.dataStore.get('bg'));
        this.dataStore.get('bg').draw();
        const pencils = this.dataStore.get('pencils');
        for (let pencil of pencils) {
            pencil.draw();
        }

        //判断铅笔移出屏幕之外后删除
        if (pencils.length > 0 && pencils[0].x <= -pencils[0].image.width) {
            this.velocity++;
            console.log(this.velocity);
            pencils.shift();
            pencils.shift();
        }

        //        console.log(pencils.length);
        //判断点添加一对铅笔,now there are only 2 pencils in the array
        if (pencils.length == 2 && pencils[0].x <= window.innerWidth * 0.5 - 0.5 * pencils[0].image.width) {
            //调试用       console.log('newpencil');
            //add pencil 
            this.createPencil();
        }
        this.dataStore.get('land').draw();
        //自调用，死循环用于刷新
        requestAnimationFrame(() => {
            this.run();
        })
    }

}