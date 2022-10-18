class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                // 需要注意，和递归摆放的位置相反
                s.push({GRAY, node});
                s.push({WHITE, node->right});
                s.push({WHITE, node->left});
            }else{
                ans.push_back(node->val);
            }
        }
        return ans;
    }
};