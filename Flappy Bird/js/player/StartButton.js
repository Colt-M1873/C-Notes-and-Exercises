import { Sprite } from "../base/Sprite.js";
import { DataStore } from "../base/DataStore.js";

export class StartButton extends Sprite{
    constructor() {
        const image = DataStore.getInstance().res.get('sb');
        super(
            image,
            0, 0,
            image.width,
            image.height,
            0, 0,
            image.width,
            image.height
        );
            this.x=window.innerWidth/2-this.image.width/2;
            this.y=window.innerHeight/2-this.image.height/2;
            
        }
      

}