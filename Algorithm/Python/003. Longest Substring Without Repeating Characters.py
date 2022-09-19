class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        from collections import defaultdict
        
        ans = 0
        l = 0
        counter = defaultdict(lambda: 0)
        
        for r in range(0, len(s)):
            while counter.get(s[r], 0) != 0:
                counter[s[l]] = counter.get(s[l], 0) - 1
                l += 1
            counter[s[r]] += 1
            ans = max(ans, r - l + 1)
        
        return ans
        