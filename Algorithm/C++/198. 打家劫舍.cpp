class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        
        vector<int> count = vector<int>(size, 0);
        count[0] = nums[0];
        count[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            count[i] = max(count[i - 2] + nums[i], count[i - 1]);
        }
        return count[size - 1];
    }
};