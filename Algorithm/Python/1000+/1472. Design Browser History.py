class BrowserHistory:

    def __init__(self, homepage: str):
        self.stack = [homepage]
        self.stackForward = []

    def visit(self, url: str) -> None:
        self.stack.append(url)
        self.stackForward = []

    def back(self, steps: int) -> str:
        for i in range(steps):
            if len(self.stack) == 1:
                break
            self.stackForward.append(self.stack.pop())
        return self.stack[-1]

    def forward(self, steps: int) -> str:
        for i in range(steps):
            if len(self.stackForward) == 0:
                break
            self.stack.append(self.stackForward.pop())
        return self.stack[-1]