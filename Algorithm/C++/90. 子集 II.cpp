class Solution {
private:
    void backtrace(vector<int>& nums, int start, vector<vector<int>> &res, vector<int> path){
        res.emplace_back(path);
        for(int i=start; i<nums.size(); i++){
            if(i != start && nums[i] == nums[i-1]){
                continue;
            }
            path.emplace_back(nums[i]);
            backtrace(nums, i+1, res, path);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;

        sort(nums.begin(), nums.end());
        backtrace(nums, 0, res, path);

        return res;
    }
};