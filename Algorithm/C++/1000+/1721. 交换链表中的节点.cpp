class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        for(int i = 1 ; i < k ; i ++){
            fast = fast->next;
        }
        ListNode* temp = fast; 

        ListNode* slow = head;
        while(fast->next){ 
            fast = fast->next;
            slow = slow->next;
        }
        swap(slow->val, temp->val); // 交换值，而不是节点。
        return head;
    }
};