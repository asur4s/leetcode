class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }

        queue<TreeNode *> q;
        TreeNode *node;
        q.push(root);
        ans.push_back({root->val});
        int size, i, count = 0;
        int node_count;

        while(!q.empty()){
            size = q.size();
            
            count++;
            node_count = 0;
            vector<TreeNode *> node_arr;
            for(i = 0; i<size; i++){
                node = q.front();
                q.pop();

                if(node->left!=nullptr){
                    q.push(node->left);
                    node_arr.push_back(node->left);
                    node_count++;
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                    node_arr.push_back(node->right);
                    node_count++;
                }
            }

            vector<int> row;
            if(count%2 == 1){
                for(i=node_count-1; i>=0; i--){
                    row.push_back(node_arr[i]->val);
                }
            }else{
                for(i=0; i<node_count; i++){
                    row.push_back(node_arr[i]->val);
                }
            }
            if(!row.empty()){
                ans.push_back(row);
            }
        }
        return ans;
    }
};