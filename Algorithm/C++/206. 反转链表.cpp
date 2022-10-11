class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        ListNode *back;

        while(cur != nullptr){
            back = cur->next;
            cur->next = pre;

            pre = cur;
            cur = back;
        }

        return pre;
    }
};