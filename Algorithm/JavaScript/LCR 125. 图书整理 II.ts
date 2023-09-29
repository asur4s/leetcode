class CQueue {
    private stackPush: number[] = [];
    private stackPop: number[] = [];

    constructor() {}

    appendTail(value: number): void {
        this.stackPush.push(value)
    }

    deleteHead(): number {
        if(this.stackPop.length === 0 && this.stackPush.length === 0){
            return -1
        }
        if(this.stackPop.length === 0){
            while(this.stackPush.length !== 0){
                this.stackPop.push(this.stackPush.pop() as number)
            }
        }
        return this.stackPop.pop() as number
    }
}