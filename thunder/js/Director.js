import { DataStore } from "./base/DataStore.js";
import { EnemyPlane1 } from "./runtime/EnemyPlane1.js";
import { Bullet } from "./runtime/Bullet.js";


export class Director {
    static getInstance() {
        if (!Director.instance) {
            Director.instance = new Director();
        }return Director.instance;
    }
    constructor() {
        this.dataStore = DataStore.getInstance();
        this.flag = true;
    }


    myPlaneEvent(x,y) {
        const m_plane = this.dataStore.get('my_plane');
        m_plane.x = x;
        m_plane.y = y;
    }

    createBullet(MyPlane_x,MyPlane_y) {
        this.dataStore.get('bullets').push(new Bullet(MyPlane_x,MyPlane_y));
    }


    intersects(birdRect, pencilRect) {
        let tw = birdRect.width;
        let th = birdRect.height;
        let rw = pencilRect.width;
        let rh = pencilRect.height;
        if (rw <= 0 || rh <= 0 || tw <= 0 || th <= 0) {
            return false;
        }
        let tx = birdRect.x;
        let ty = birdRect.y;
        let rx = pencilRect.x;
        let ry = pencilRect.y;
        rw += rx;
        rh += ry;
        tw += tx;
        th += ty;
        return (
            (rw < rx || rw > tx) &&
            (rh < ry || rh > ty) &&
            (tw < tx || tw > rx) &&
            (th < ty || th > ry));
    }


    enemy_p1_option(my_plane,bullets) {
        const enemy_p1s = this.dataStore.get('enemy_p1s');
        if(enemy_p1s.length < 10){
            this.dataStore.get('enemy_p1s').push(new EnemyPlane1());
        }
        for(let p1s of enemy_p1s){
            p1s.draw();
        }
        for(var i=0;i<enemy_p1s.length;i++){
            if(enemy_p1s[i].y>=window.innerHeight){
                enemy_p1s.splice(i,1);
            }
        }
        for(let p1s of enemy_p1s) {
            if(this.intersects(my_plane,p1s)){
                this.flag = false;
            }
        }

        for(var i=0;i<enemy_p1s.length;i++){
            for( var j=0;j<bullets.length;j++){
                if(this.intersects(enemy_p1s[i],bullets[j])){
                    enemy_p1s.splice(i,1);
                    bullets.splice(j,1);
                    this.dataStore.get('score').scoreNum++;
                }
            }
        }
    }



    run () {//开始
        if(this.flag){
            this.dataStore.get('bg').draw(); 
            this.dataStore.get('my_plane').draw();
            this.enemy_p1_option(this.dataStore.get('my_plane'),this.dataStore.get('bullets'));


            const bullets = this.dataStore.get('bullets');
            const myPlane= this.dataStore.get('my_plane');
            if (bullets.length > 0 && bullets[0].y <=-bullets[0].image.height) {
                bullets.shift();
            }
            console.log(bullets[0].y)
            if (bullets.length <= 30 && myPlane.y-bullets[bullets.length-1].y >= 50 ) {           
             this.createBullet(myPlane.x+myPlane.image.width/2,myPlane.y);
            }

            for (let bullet of bullets) {
                bullet.draw();
            }
            this.dataStore.get('score').draw();


            requestAnimationFrame(() => {
                //console.log(1);
                this.run();
            });
        }
    }
}