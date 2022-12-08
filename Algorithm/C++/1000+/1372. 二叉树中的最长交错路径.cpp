/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxAns;
    /* 0=>left, 1=>right */
    void dfs(TreeNode *root, bool dir, int len){
        if(root == nullptr){
            return;
        }
        if(len > maxAns){
            maxAns = len;
        }
        int len_left, len_right;
        if(dir == false){
            len_left = 1;
            len_right = len+1;
        }else{
            len_left = len+1;
            len_right = 1;
        }
        dfs(root->left, 0, len_left);
        dfs(root->right, 1, len_right);
    }
public:
    int longestZigZag(TreeNode* root) {
        maxAns = 0;
        dfs(root, 0, 0);
        dfs(root, 1, 0);
        return maxAns;
    }
};