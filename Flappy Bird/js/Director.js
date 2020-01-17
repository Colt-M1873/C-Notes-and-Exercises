import { DataStore } from "/js/base/DataStore.js";
import { UpPencil } from "./runtime/UpPencil.js";
import { DownPencil } from "./runtime/DownPencil.js";
import { Bird } from '/js/player/Bird.js';

import { Score } from "/js/player/Score.js";
import { StartButton } from "./player/StartButton.js";
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
        this.velocity = 0;
        this.live = true;//judge if the game is continuing
    }

    createPencil() {
        const minTop = window.innerHeight / 8;
        const maxTop = window.innerHeight / 2;
        const top = minTop + (maxTop - minTop) * Math.random();
        this.dataStore.get('pencils').push(new UpPencil(top));
        this.dataStore.get('pencils').push(new DownPencil(top));
    }
    //点击鼠标后的小鸟事件
    birdEvent() {
        console.log('1');
        const bird = this.dataStore.get('bird');
        bird.time = 0;
        bird.initY = bird.y;
    }
    //矩形碰撞检测
    intersects(birdRect, pencilRect) {
        let tw = birdRect.width;
        let th = birdRect.height;
        let rw = pencilRect.width;
        let rh = pencilRect.height;
        if (rw <= 0 || rh <= 0 || tw <= 0 || th <= 0) {
            return false;
        }
        let tx = birdRect.x;
        let ty = birdRect.y;
        let rx = pencilRect.x;
        let ry = pencilRect.y;
        rw += rx;
        rh += ry;
        tw += tx;
        th += ty;
        // overflow || intersect 
        return ((rw < rx || rw > tx) &&
            (rh < ry || rh > ty) &&
            (tw < tx || tw > rx) &&
            (th < ty || th > ry));
    }

    check() {
        //check crash wiht floor
        const bird = this.dataStore.get('bird');
        const land = this.dataStore.get('land');
        const pencils=this.dataStore.get('pencils');
        if (bird.y + bird.height >= land.y) {
            console.log('crash floor');
            this.live = false;
            return; //void after return menas suspend this program immediately
        }
     
        for (let pencil of pencils) {
            console.log(this.intersects(bird, pencil));
            //console.log(bird.x,bird.y,pencil.x,pencil.y);
            console.log(pencil);
            
            // console.log(bird.width,bird.height,pencil.image.width,pencil.image.height);
            if (this.intersects(bird, pencil)) {
                console.log('crash pillar');
                this.live = false;
                return; //void after return menas suspend this program immediately
            }
        }
    }


    run() {
        this.check();
        if (this.live) {
            //      console.log(this.dataStore.get('bg'));
            this.dataStore.get('bg').draw();
            const pencils = this.dataStore.get('pencils');
            for (let pencil of pencils) {
                pencil.draw();
            }

            //判断铅笔移出屏幕之外后删除
            if (pencils.length > 0 && pencils[0].x <= -pencils[0].image.width) {
                this.velocity++;
               // console.log(this.velocity);
                pencils.shift();
                pencils.shift();
                this.dataStore.get('score').isAdd = true;

            }

            //        console.log(pencils.length);
            //判断点添加一对铅笔,now there are only 2 pencils in the array
            if (pencils.length == 2 && pencils[0].x <= window.innerWidth * 0.5 - 0.5 * pencils[0].image.width) {
                //调试用       console.log('newpencil');
                //add pencil 
                this.createPencil();

            }

            //scorecounter
            const bird = this.dataStore.get('bird');
            const firstpencil = pencils[0];
            if (this.dataStore.get('score').isAdd && bird.x > firstpencil.x + firstpencil.image.width) {
                this.dataStore.get('score').num++;
                this.dataStore.get('score').isAdd = false;
            }

            this.dataStore.get('land').draw();
            this.dataStore.get('bird').draw();
            this.dataStore.get('score').draw();
            //自调用，死循环用于刷新
            requestAnimationFrame(() => {
                this.run();
            })
        }
        else {
            this.dataStore.get('sb').draw();
        }

    }


}