class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *p = head;
        while(p != nullptr){
            if(p->val == val){
                pre->next = p->next;
                delete p;
                p = pre->next;
            }else{
                pre = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};