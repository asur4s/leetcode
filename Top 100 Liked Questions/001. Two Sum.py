
# Method 1: brute force (TLE)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(0, n-1):
            for j in range(i+1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]

# Method 2: 
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(0, n-1):
            temp = target - nums[i]
            if temp in nums[i+1:]:
                return [i, i+1+nums[i+1:].index(temp)]

# Method 3: hash table
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_table = dict()
        for i, num in enumerate(nums):
            if target - num in hash_table:
                return [hash_table[target - num], i]
            hash_table[num] = i
