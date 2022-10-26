class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> sumMap;
        int sum = 0;
        ListNode *dummy = new ListNode(0, head);

        ListNode *cur = dummy;
        ListNode *node;
        while(cur != nullptr){
            sum += cur->val;
            sumMap[sum] = cur;
            cur = cur->next;
        }

        // 不能合并为一个循环
        sum = 0;
        cur = dummy;
        while(cur != 0){
            sum += cur->val;
            // memory leak
            cur->next = sumMap[sum]->next;
            cur = cur->next;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};