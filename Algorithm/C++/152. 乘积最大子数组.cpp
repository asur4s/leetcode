class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int preMin = nums[0], preMax = nums[0];
        int maxAns = nums[0], size = nums.size();
        int pX, pN;
        for(int i=1; i<size; i++){
            pX = preMax;
            pN = preMin;
            if(nums[i] > 0){
                preMin = min(pN * nums[i], nums[i]);
                preMax = max(pX * nums[i], nums[i]);
            }else{
                preMin = min(pX * nums[i], nums[i]);
                preMax = max(pN * nums[i], nums[i]);
            } 
            if(preMax > maxAns){
                maxAns = preMax;
            }
        }
        return maxAns;
    }
};