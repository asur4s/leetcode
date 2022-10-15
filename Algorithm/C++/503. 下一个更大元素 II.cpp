// 执行用时：击败 94.54%
// 内存消耗：击败 90.45%
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        
        for(int i=0; i<n; i++){
            while(!s.empty() && nums[i] > nums[s.top()]){
                int prev = s.top();
                ans[prev] = nums[i];
                s.pop();
            }
            s.push(i);
        }

        int top;
        int size = s.size();
        for(int i=0; i<size; i++){
            top = s.top();
            ans[top] = -1;
            for(int j=0; j<=top; j++){
                if(nums[j] > nums[top]){
                    ans[top] = nums[j];
                    break;
                }
            }
            s.pop();
        }

        return ans;
    }
};