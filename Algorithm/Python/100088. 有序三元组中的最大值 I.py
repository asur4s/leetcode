"""

# 方案2: 固定 k
max_diff[i] = max(max_diff[i-1], pre_max - nums[i])
"""


class Solution:

    def maximumTripletValue(self, nums):
        n = len(nums)
        max_diff = [0] * n
        pre_max = nums[0]
        max_diff[0] = 0
        for i in range(1, n):
            max_diff[i] = max(max_diff[i - 1], pre_max - nums[i])
            pre_max = max(pre_max, nums[i])
        # print(max_diff)
        ans = 0
        for k in range(2, n):
            ans = max(ans, max_diff[k-1] * nums[k])
        return ans


solution = Solution()
res = solution.maximumTripletValue([2,3,1])
print(res)
