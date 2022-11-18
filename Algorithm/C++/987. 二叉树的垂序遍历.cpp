class Solution {
private:
    vector<tuple<int, int, int>> nodes;
    void dfs(TreeNode* root, int col, int row){
        if(root == nullptr){
            return;
        }
        nodes.emplace_back(col, row, root->val);
        dfs(root->left, col-1, row+1);
        dfs(root->right, col+1, row+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;
        int cur_row = INT_MIN;

        for(const auto &[col, row, val]: nodes){
            if(cur_row != col){
                cur_row = col;
                ans.emplace_back();
            }
            ans.back().emplace_back(val);
        }

        return ans;
    }
};