class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        
        int total = 0;
        for (ListNode *cur = head->next; cur; cur = cur->next) {
            if (cur->val == 0) {
                ListNode *node = new ListNode(total);
                tail->next = node;
                tail = tail->next;
                total = 0;
            } else {
                total += cur->val;
            }
        }
        
        return dummy->next;
    }
};