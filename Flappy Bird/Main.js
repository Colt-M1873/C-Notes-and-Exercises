import { ResourceLoader } from '/js/base/ResourceLoader.js';
import { DataStore } from '/js/base/DataStore.js';
import { Background } from '/js/runtime/Background.js';
import { Land } from '/js/runtime/Land.js';
import { Director } from '/js/Director.js';
import { Pencil } from './js/runtime/Pencil.js';
// 负责各种资源调度
export class Main {
    constructor() {
        //准备资源
        //准备画板和画笔
        this.canvas = document.getElementById('game');
        this.ctx = this.canvas.getContext('2d');
        //将datastore准备好
        this.dataStore = DataStore.getInstance();
        //准备图片，放入到DataStore中
        new ResourceLoader().onLoaded((res) => {
            this.res = res;
            this.init();
        });

    }
    init() {
 //????????????       console.log(this.dataStore.res);
        this.dataStore.res = this.res;
        this.dataStore.ctx = this.ctx;
        //准备背景
        this.dataStore.put('bg', new Background());
        //准备陆地
        this.dataStore.put('land', new Land());
         this.dataStore.put('pencils',[]);
        
        Director.getInstance().createPencil();
        Director.getInstance().run();


    }
}


