import { DataStore } from "../base/DataStore.js";
import { Sprite } from "../base/Sprite.js";

export class EnemyPlane1 extends Sprite {

    constructor(start_y) {
        let image;
        const ran = Math.random()*100;
        if(ran<=60&&ran>=0){
            image = DataStore.getInstance().res.get('ep1');
        }else if(ran>60&&ran<=90){
            image = DataStore.getInstance().res.get('ep2');
        }else{
            image = DataStore.getInstance().res.get('ep3');
        }
        super(
            image,
            0,0,
            image.width,
            image.height,
            0,0,
            image.width,
            image.height
        );
        this.x = Math.random()*330;
        this.y = (Math.random()*window.innerHeight)-900;
    }
    draw (){
        this.y = this.y + 4;
        super.draw();
    }
}