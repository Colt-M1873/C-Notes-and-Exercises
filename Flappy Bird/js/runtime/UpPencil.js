import { DataStore } from "../base/DataStore.js";
import { Pencil } from "/js/runtime/Pencil.js";

export class UpPencil extends Pencil {
    constructor(top) {
        const image = DataStore.getInstance().res.get('pu');
        super(image);
        this.y = top - image.height;
    }
}