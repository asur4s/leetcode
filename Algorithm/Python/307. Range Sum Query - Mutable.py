class NumArray:
    
    def lowbit(self, n):
        return n & (-n)

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.counts = [0 for i in range(len(nums))]
        
        for i in range(len(nums)):
            if i == 0:
                self.counts[0] = self.nums[0]
            else:
                for j in range(i + 1 - self.lowbit(i), i + 1):
                    self.counts[i] += self.nums[j]

    def update(self, index: int, val: int) -> None:
        if index == 0:
            self.nums[0] = val
            self.counts[0] = val
        else:
            diff = self.nums[index] - val
            self.nums[index] = val
            while index < len(self.nums):
                self.counts[index] -= diff
                index = index + self.lowbit(index)

    def sumRange(self, left: int, right: int) -> int:
        if left == right:
            return self.nums[left]
        else:
            idLeft, leftSum, rightSum = left, 0, 0
            while left > 0:
                leftSum += self.counts[left]
                left = left - self.lowbit(left)
            while right > 0:
                rightSum += self.counts[right]
                right = right - self.lowbit(right)
                
            if idLeft == 0:
                return rightSum + self.counts[0]
            else:
                return rightSum - leftSum + self.nums[idLeft]
            
