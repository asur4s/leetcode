class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int size, i;
        TreeNode *node;
        int ans;
        bool flag;

        while(!q.empty()){
            size = q.size();
            flag = true;

            for(i=0; i<size; i++){
                node = q.front();
                q.pop();

                if(flag && node->left == nullptr && node->right == nullptr){
                    ans = node->val;
                    flag = false;
                }
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};