import { DataStore } from "../base/DataStore.js";
import { Sprite } from "../base/Sprite.js";

export class MyPlane extends Sprite {
    constructor(start_y) {
        const image = DataStore.getInstance().res.get('mp');
        super(
            image,
            0,0,
            image.width,
            image.height,
            150,window.innerHeight/2,
            image.width,
            image.height
        );
    }
    draw (){
        super.draw();
    }
}