class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 反转链表
        ListNode *back;
        ListNode *pre = nullptr; 
        ListNode *cur = slow->next;
        while (cur != nullptr) {
            back = cur->next;
            cur->next = pre;
            pre = cur;
            cur = back;
        }

        int ans = 0;
        ListNode* x = head;
        ListNode* y = pre;
        while (y) {
            ans = max(ans, x->val + y->val);
            x = x->next;
            y = y->next;
        }
        return ans;
    }
};