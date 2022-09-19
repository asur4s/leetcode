
# Method 1: TLE
class StockPrice:

    def __init__(self):
        self.times = []
        self.prices = []
        self.currentT = 0

        
    def update(self, timestamp: int, price: int) -> None:
        if timestamp > self.currentT:
            self.currentT = timestamp
        if timestamp not in self.times:
            self.times.append(timestamp)
            self.prices.append(price)
        else:
            index = self.times.index(timestamp)
            self.prices[index] = price

            
    def current(self) -> int:
        index = self.times.index(self.currentT)
        
        return self.prices[index]
        
        
    def maximum(self) -> int:
        return max(self.prices)
    
    
    def minimum(self) -> int:
        return min(self.prices)


# Method 2: minHeap maxHeap

