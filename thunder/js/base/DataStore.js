export class DataStore {

    static getInstance() {
        if(!DataStore.instance){
            DataStore.instance = new DataStore();
        }
        return DataStore.instance;
    }//单例模式

    constructor() {
        this.map = new Map();
    }//构造方法

    put (key, value){
        this.map.set(key, value);
    }//放入方法

    get (key) {
        return this.map.get(key);
    }//取出方法
    clearDataStore() {
        this.map.clear();
    }

}