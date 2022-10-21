class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        ListNode dummy;
        dummy.next = head;
        ListNode *p1, *p2, *p3, *p4, *cur = &dummy;
        while(cur != nullptr && cur->next != nullptr && cur->next->next != nullptr){
            p1 = cur;
            p2 = cur->next;
            p3 = cur->next->next;
            p4 = cur->next->next->next;

            p1->next = p3;
            p3->next = p2;
            p2->next = p4;

            cur = cur->next->next;
        }
        return dummy.next;
    }
};