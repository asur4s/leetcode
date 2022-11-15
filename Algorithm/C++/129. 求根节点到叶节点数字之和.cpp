class Solution {
private:
    int dfs(TreeNode* root, int pre){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return pre*10 + root->val;
        }

        int cur = pre*10 + root->val;
        return dfs(root->left, cur) + dfs(root->right, cur);
    }
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};