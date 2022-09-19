class StockSpanner:

    def __init__(self):
        self.container = []

    def next(self, price: int) -> int:
        res = 1
        while self.container and self.container[-1][0] <= price:
            res += self.container.pop()[1]
        self.container.append((price, res))
        return res
        