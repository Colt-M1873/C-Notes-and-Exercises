import { Sprite } from "../base/Sprite.js";
import { DataStore } from "../base/DataStore.js";

export class Background extends Sprite {

    constructor() {
        const image = DataStore.getInstance().res.get('bg');
        super(
            image,
            0, 0,
            image.width,
            image.height,
            0, 0,
            image.width,
            image.height
        );

    }

}