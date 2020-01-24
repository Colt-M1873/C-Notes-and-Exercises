import { DataStore } from "../base/DataStore.js";
import { Sprite } from "../base/Sprite.js";


export class Bullet extends Sprite {
    constructor(x, y) {
        const image = DataStore.getInstance().res.get('bullet');
        super(
            image,
            0, 0,
            image.width,
            image.height,
            x, y,//飞机图片位置
            image.width,
            image.height
        );
    }

    draw() {
        this.y = this.y - 5;
        super.draw();
    }

}