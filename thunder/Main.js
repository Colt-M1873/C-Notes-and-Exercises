import { ResourceLoader } from "./js/base/ResourceLoader.js";
import { DataStore } from "./js/base/DataStore.js";
import { Background } from "./js/runtime/Background.js";
import { Director } from "./js/Director.js";
import { MyPlane } from "./js/runtime/MyPlane.js";
import { EnemyPlane1 } from "./js/runtime/EnemyPlane1.js";
import { Score } from "./js/player/Score.js";


export class Main {
    constructor() {

        this.canvas = document.getElementById('game');//获取画板
        this.ctx = this.canvas.getContext('2d');//获取画板上的画笔
        this.dataStore = DataStore.getInstance();
        new ResourceLoader().onLoaded((res) => {
            this.res = res;
            this.init();
        });
    }
    init() {
        this.dataStore.res = this.res;//这里应该是为资源仓库获取到资源以及画笔
        this.dataStore.ctx = this.ctx;//获取画笔
        //this.dataStore.put('bg',new BackGround());
        this.dataStore.put('bg', new Background());
        this.dataStore.put('my_plane',new MyPlane());
        this.dataStore.put('enemy_p1s',[]);
        this.dataStore.put('bullets',[]);
        this.dataStore.put('score',new Score());
        this.registerEvent();
       //  Director.getInstance().createBullet(200,500);
       Director.getInstance().createBullet(this.dataStore.get('my_plane').x+this.dataStore.get('my_plane').image.width/2,this.dataStore.get('my_plane').y); 

       Director.getInstance().run();
    }
    registerEvent() {
        const director = Director.getInstance();
        this.canvas.addEventListener('mousemove',() => {
            director.myPlaneEvent(event.clientX-30,event.clientY-40);
        });
    }
}