class MinStack {
    protected dataStack: number[] = [];
    protected minStack: number[] = [];

    constructor() { }

    push(val: number): void {
        this.dataStack.push(val)
        if (this.minStack.length === 0) {
            this.minStack.push(val)
        } else {
            this.minStack.push(Math.min(this.getMin(), val))
        }
    }

    pop(): void {
        if (this.dataStack.length === 0) {
            return
        }
        this.dataStack.pop()
        this.minStack.pop()
    }

    top(): number {
        if (this.dataStack.length === 0) {
            return Infinity
        }
        return this.dataStack[this.dataStack.length - 1]
    }

    getMin(): number {
        if (this.minStack.length === 0) {
            return Infinity
        }
        return this.minStack[this.minStack.length - 1]
    }
}