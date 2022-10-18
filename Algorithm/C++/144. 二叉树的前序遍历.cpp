class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        int WHITE = 0, GRAY = 1;
        vector<int> ans;
        stack<pair<int, TreeNode*>> s;
        s.push({WHITE, root});

        TreeNode *node;
        while (!s.empty()){
            int color = s.top().first;
            node = s.top().second;
            s.pop();

            if(node == nullptr){ continue; }
            if(color == WHITE){
                s.push({WHITE, node->right});
                s.push({WHITE, node->left});
                s.push({GRAY, node});
            }else{
                ans.push_back(node->val);
            }
        }
        return ans;
    }
};