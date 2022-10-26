class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        dummy->next = list1;
        ListNode *cur = dummy;
        
        ListNode *p1, *p2;
        for(int i = 0; i < a; i ++ ) cur = cur->next;
        p1 = cur;

        b = b - a + 1;
        for (int i = 0; i < b; i ++ ) cur = cur->next;
        p2 = cur->next;

        ListNode* list2tail = list2;
        while (list2tail != nullptr && list2tail->next != nullptr) list2tail = list2tail->next;

        p1->next = list2;
        list2tail->next = p2;

        return dummy->next;
    }
};