class Solution {
private:
    int getLength(ListNode* head){
        int count = 0;
        while(head != nullptr){
            count++;
            head = head->next;
        }
        return count;
    }
    TreeNode* buildTree(ListNode* &head, int l, int r){
        if(l > r){
            return nullptr;
        }
        int mid = (l + r + 1)/2;
        
        TreeNode *root = new TreeNode();
        root->left = buildTree(head, l, mid-1);
        root->val = head->val;
        cout<<mid<<" "<<root->val<<endl;
        head = head->next;
        root->right = buildTree(head, mid+1, r);
        return root; 
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, 0, getLength(head) - 1);
    }
};