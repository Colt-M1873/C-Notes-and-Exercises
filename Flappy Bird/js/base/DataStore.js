//数据中心类，用于存取数据
//利用现有容器结构实现 用map
//必须保证水桶只有一个，运用单例模式，一个类只产出一个对象
//此类不能用new来创建对象，只能用getInstance方法来获取对象
//中介模式??查
export class DataStore {
    //此方法用于外界获取对象，保证对象唯一    
    static getInstance() {
        //若无此属性，则创建对象给instance属性，如果有，直接返回
        if (!DataStore.instance) {
            DataStore.instance = new DataStore();
        }
        return DataStore.instance;
    }
    constructor() {
        this.map = new Map();
    }
    //存储方法
    put(key, value) {//类内部的map集合，用于存储
        this.map.set(key, value);//链式调用，查
    }
    //取出方法
    get(key) {//取出，用key来取到value
        return this.map.get(key);
    }
    //清除方法
}