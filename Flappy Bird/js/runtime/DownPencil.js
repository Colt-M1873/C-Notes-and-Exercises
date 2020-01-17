import { DataStore } from "../base/DataStore.js";
import { Pencil } from "/js/runtime/Pencil.js";

export class DownPencil extends Pencil {
    constructor(top) {
        const image = DataStore.getInstance().res.get('pd');
        super(image);

        this.y=top+window.innerHeight/4;
    }
}