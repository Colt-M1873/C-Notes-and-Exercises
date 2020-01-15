import { Resource } from "/js/base/Resource.js";

export class ResourceLoader {
    constructor() {
        //将图片简短名字和完整地址变成map集合
        this.map = new Map(Resource)
        //将完整地址转换为Image对象
        for (let [key, value] of this.map) {
            let image = new Image();
            image.src = value;
            this.map.set(key, image);
        }
    }

    //保证加载完再返回给调用者,使用回调函数
    onLoaded(callback) {
        let loadedCount = 0;
        //保证所有图片加载完成之后再用callback函数将资源回传
        for (let value of this.map.values()) {
            //箭头函数，查
            value.onload = () => {
                loadedCount++;
                if (loadedCount >= this.map.size) {
                    callback(this.map);
                }
            }
        }
    }
}