class Solution {
public:
    int maxAns;
    /* 1 => left, 0 => right */
    void dfs(TreeNode* root, bool left, int len) {
        if(root == nullptr){
            return;
        }

        maxAns = max(maxAns, len);
        int len_left, len_right;
        len_left = left? 1: len+1;
        len_right = left? len+1: 1;

        dfs(root->left, 1, len_left);
        dfs(root->right, 0, len_right);
    } 

    int longestZigZag(TreeNode* root) {
        if (root == nullptr) return 0;

        maxAns = 0;
        dfs(root, 0, 0);
        dfs(root, 1, 0);

        return maxAns;
    }
};