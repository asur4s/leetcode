class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int maxAns = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            pre = max(pre+nums[i], nums[i]);
            if(maxAns < pre){
                maxAns = pre;
            }
        }
        return maxAns;
    }
};