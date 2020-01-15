import { Sprite } from "/js/base/Sprite.js";
import { Director } from '/js/Director.js';
export class Pencil extends Sprite{
    constructor(image){
        super(
            image,
            0, 0,
            image.width,
            image.height,
            window.innerWidth, 0,
            image.width,
            image.height
        );

    }
    draw(){
        // if(Director.getInstance().velocity>6){
        //     Director.getInstance().velocity=6;
        // }
        this.x=this.x-2-Director.getInstance().velocity*0.1;
        super.draw()
    }

}