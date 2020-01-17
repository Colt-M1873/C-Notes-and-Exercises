import { Sprite } from "../base/Sprite.js";

export class Score extends Sprite {

    constructor() {
        super(
            null,
            0, 0,
            0, 0,
            0, 0,
            0, 0,
        );
        this.num=0;
        this.isAdd=true;      
    };
  
    draw() {
        this.dataStore.ctx.font = '25px Arial';
        this.dataStore.ctx.fillStyle = '#ffcbeb';
        this.dataStore.ctx.fillText(
            this.num,
            window.innerWidth / 2,
            window.innerHeight / 18,
            1000
        );
    }




}