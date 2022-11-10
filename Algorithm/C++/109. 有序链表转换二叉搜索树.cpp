class Solution {
private:
    deque<int> values;

public:
    TreeNode* buildTree(int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right + 1) / 2;
        TreeNode* root = new TreeNode(values[mid]);
        root->left = buildTree(left, mid-1);
        root->right = buildTree(mid+1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        while(head != nullptr){
            values.push_back(head->val);
            head = head->next;
        }
        return buildTree(0, values.size() - 1);
    }
};