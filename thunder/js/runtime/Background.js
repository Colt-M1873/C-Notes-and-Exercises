import { DataStore } from "../base/DataStore.js";
import { Sprite } from "../base/Sprite.js";

export class Background extends Sprite {
    constructor() {
        const image = DataStore.getInstance().res.get('bg');
        super(
            image,
            0,0,
            image.width,
            image.height,
            0,0,
            image.width,
            image.height
        );
    }
    draw() {
        this.y = this.y + 2;
  //      console.log(this.y);
        if (this.y >= 0) {
            this.y = -this.image.height/2;
        }
        super.draw();
    };
}