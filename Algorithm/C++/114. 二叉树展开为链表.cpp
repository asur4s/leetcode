class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode *p1, *p2, *p3, *p4, *node;
        while(cur != nullptr){
            p1 = cur;
            p4 = cur->right;
            if(cur->left != nullptr){
                p2 = cur->left;
                node = p2;
                while(node->right != nullptr){
                    node = node->right;
                }
                p3 = node;
                
                p1->left = nullptr;
                p1->right = p2;
                p3->right = p4;
            }
            cur = cur->right;
        }
    }
};