class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }

        queue<TreeNode *> q;
        TreeNode* node;
        int size, i, max_val;
        q.push(root);

        while(!q.empty()){
            size = q.size();
            max_val = INT_MIN;

            for(i=0; i<size; i++){
                node = q.front();
                q.pop();

                if(node->val > max_val){
                    max_val = node->val;
                }
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};