class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == nullptr){
            return ans;
        }

        queue<TreeNode *> q;
        TreeNode* node;
        int size, i;
        double sum;
        q.push(root);

        while(!q.empty()){
            size = q.size();
            sum = 0;

            for(i=0; i<size; i++){
                node = q.front();
                q.pop();

                sum += node->val;
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }

            ans.push_back(sum/size);
        }
        return ans;
    }
};