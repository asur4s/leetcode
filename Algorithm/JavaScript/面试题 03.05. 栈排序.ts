class SortedStack {
    private helpStack: number[];
    private dataStack: number[];

    constructor() {
        this.helpStack = [];
        this.dataStack = [];
    }

    push(val: number): void {
        if (this.isEmpty()) {
            this.dataStack.push(val);
            return
        }
        this.dataStack.push(val)
        // 排序
        this.helpStack = []
        while (this.dataStack.length !== 0) {
            let cur = this.dataStack.pop() as number
            while (this.helpStack.length !== 0 && cur < this.helpStack[this.helpStack.length - 1]) {
                this.dataStack.push(this.helpStack.pop() as number)
            }
            this.helpStack.push(cur)
        }

        while (this.helpStack.length !== 0) { // 移动到 dataStack
            this.dataStack.push(this.helpStack.pop() as number);
        }
        console.log(val, this.dataStack, this.helpStack);

    }

    pop(): void {
        this.dataStack.pop();
    }

    peek(): number {
        if (this.isEmpty()) {
            return -1;
        }
        return this.dataStack[this.dataStack.length - 1]
    }

    isEmpty(): boolean {
        return this.dataStack.length === 0
    }
}
