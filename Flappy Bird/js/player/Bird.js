import { Sprite } from "../base/Sprite.js";
import { DataStore } from '/js/base/DataStore.js';

export class Bird extends Sprite {
    constructor() {
        const image = DataStore.getInstance().res.get('bird');
        super(
            image,
            0, 0,
            image.width,
            image.height,
            0, 0,
            image.width,
            image.height
        );
        this.x = window.innerWidth / 4;
        this.y = window.innerHeight / 2;
        this.index = 0;

        this.srcXs = [9, 61, 113];//[9,27+34,45+34+34];
        this.srcY = 10;
        this.cWidth = 34;
        this.cHeight = 24;
        this.width = 34;
        this.height = 24;
        this.index = 0;
        this.time = 0;
        this.initY = this.y;
    }
    draw() {
        this.index = this.index + 0.2;
        if (this.index >= 3) {
            this.index = 0;
        }
        //自由落体
        const g = 0.98 / 2.4;
        const offsetY =  (g + this.time * (this.time-30)) / 2;//减30是为了向上跳再往下走
        this.y = this.initY + offsetY;

        this.time++;

        this.dataStore.ctx.drawImage(
            this.image,
            this.srcXs[Math.floor(this.index)], this.srcY,
            this.cWidth, this.cHeight,
            this.x, this.y,
            this.width, this.height
        )


    }

}