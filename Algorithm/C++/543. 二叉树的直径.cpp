class Solution {
private:
    int ans;
    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int L = depth(root->left);
        int R = depth(root->right);
        ans = max(ans, L+R);
        return max(L, R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        ans = 0;
        depth(root);
        return ans;
    }
};