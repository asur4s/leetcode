class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }

        queue<TreeNode *> q;
        TreeNode* node;
        q.push(root);
        int size, i;

        while(!q.empty()){
            size = q.size();
            vector<int> row;

            for(i=0; i<size; i++){
                node = q.front();
                q.pop();

                row.push_back(node->val);
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            ans.push_back(row.back());
        }

        return ans;
    }
};