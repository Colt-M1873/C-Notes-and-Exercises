import { DataStore } from "./DataStore.js";


export class Sprite {
    constructor(
        image,
        srcX,srcY,
        cWidth,cHeight,
        x,y,
        width, height
    ) {
        this.image = image;
        this.srcX = srcX;
        this.srcY = srcY;
        this.cWidth = cWidth;
        this.cHeight = cHeight;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;

        this.dataStore = DataStore.getInstance();
    }
    draw() {
        this.dataStore.ctx.drawImage(
            this.image,
            this.srcX,this.srcY,
            this.cWidth,this.cHeight,
            this.x,this.y,
            this.width,this.height
        );

    }
}