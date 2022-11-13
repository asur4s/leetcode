class Solution {
private:
    int maxValue;
    int dfs(TreeNode *root){
        if(root == nullptr){
            return 0;
        }

        int l = dfs(root->left);
        int r = dfs(root->right);
        if(l < 0){
            l = 0;
        }
        if(r<0){
            r = 0;
        }
        maxValue = max(l+r+root->val, maxValue);

        return l<0 && r<0? root->val: root->val+max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        maxValue = INT_MIN;
        dfs(root);
        return maxValue;
    }
};