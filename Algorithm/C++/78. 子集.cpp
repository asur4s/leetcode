class Solution {
private:
    void backtrack(const vector<int>& nums, int start, vector<vector<int>> &res, vector<int> selected){
        res.emplace_back(selected);
        for(int i=start; i < nums.size(); i++){
            selected.emplace_back(nums[i]);
            backtrack(nums, i+1, res, selected);
            selected.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        vector<int> selected;
        backtrack(nums, 0, res, selected);

        return res;
    }
};