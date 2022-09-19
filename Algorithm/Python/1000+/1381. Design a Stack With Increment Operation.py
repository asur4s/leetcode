class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = []
        self.maxSize = maxSize
        
    def push(self, x: int) -> None:
        if len(self.stack) < self.maxSize:
            self.stack.append(x)
        
    def pop(self) -> int:
        if len(self.stack) == 0:
            return -1     
        else:
            return self.stack.pop()

    def increment(self, k: int, val: int) -> None:
        for i in range(k):
            if i >= len(self.stack):
                break
            self.stack[i] += val