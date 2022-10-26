class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == nullptr) return true;
        if(root == nullptr) return false;
        return dfs(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
    bool dfs(ListNode *head,TreeNode *node){
        if(head == nullptr) return true;
        if(node == nullptr) return false;
        if(head->val != node->val) return false;
        return dfs(head->next,node->left) || dfs(head->next,node->right);
    }
};