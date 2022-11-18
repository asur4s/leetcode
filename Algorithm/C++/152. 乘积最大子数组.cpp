class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxAns = nums[0];
        int preMax = nums[0], preMin = nums[0];
        int pX, pN;
        for(int i=1; i<nums.size(); i++){
            pX = preMax;
            pN = preMin;
            if(nums[i] > 0){
                preMax = max(pX * nums[i], nums[i]);
                preMin = min(pN * nums[i], nums[i]);
            }else{
                preMax = max(pN * nums[i], nums[i]);
                preMin = min(pX * nums[i], nums[i]);
            }
            if(maxAns < preMax){
                maxAns = preMax;
            }
        }
        return maxAns;
    }
};