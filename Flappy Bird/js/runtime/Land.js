import { DataStore } from "/js/base/DataStore.js";
import {Sprite} from '/js/base/Sprite.js';

export class Land extends Sprite{
   
    constructor() {
        const image = DataStore.getInstance().res.get('land');
        super(
            image,
            0, 0,
            image.width,
            image.height,
            0, window.innerHeight - image.height,
            image.width,
            image.height
        );

    }

    draw (){
        this.x=this.x-2;
        if(this.x <= window.innerWidth-this.image.width){
            this.x=0;
        }
        super.draw();

    }

}