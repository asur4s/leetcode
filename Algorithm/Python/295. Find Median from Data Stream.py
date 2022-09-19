from heapq import heappush, heappop

class MedianFinder:

    def __init__(self):
        self.minHeap = [float('inf')]
        self.maxHeap = [float('inf')]

    def addNum(self, num: int) -> None:
        minValue = + self.minHeap[0]
        maxValue = - self.maxHeap[0]
        
        if num > minValue or (maxValue < num < minValue) and len(self.minHeap) == len(self.maxHeap):
            heappush(self.minHeap, num)
        else:
            heappush(self.maxHeap, -num)
        
        if len(self.minHeap) - len(self.maxHeap) > 1:
            heappush(self.maxHeap, -heappop(self.minHeap))
        elif len(self.maxHeap) - len(self.minHeap) > 0:
            heappush(self.minHeap, -heappop(self.maxHeap))
        

    def findMedian(self) -> float:
        if len(self.minHeap) == len(self.maxHeap):
            return (self.minHeap[0] + -self.maxHeap[0]) / 2
        else:
            return self.minHeap[0]
        