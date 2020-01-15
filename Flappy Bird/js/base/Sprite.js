import { DataStore } from "./DataStore.js";

//精灵类，所有演员的基类
export class Sprite{//srcx为源图片裁剪点位置cwidth为裁剪宽度，x，y为放置位置，width为放置图片宽度
    constructor(image,srcX,srcY,cWidth,cHeight,x,y,Width,Height){
        this.image=image;
        this.srcX=srcX;
        this.srcY=srcY;
        this.cWidth=cWidth;
        this.cHeight=cHeight;
        this.x=x;
        this.y=y;
        this.Width=Width;
        this.Height=Height;

        this.dataStore=DataStore.getInstance();
    }
    draw(){
        this.dataStore.ctx.drawImage(
            this.image,
            this.srcX,this.srcY,
            this.cWidth,this.cHeight,
            this.x,this.y,
            this.Width,this.Height  
        );      
    }



}