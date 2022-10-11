class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode();
        ListNode *right = new ListNode();
        ListNode *l = left;
        ListNode *r = right;

        while (nullptr != head){  
            if(head->val >= x){
                r->next = head;
                r = r->next;
            }else{
                l->next = head;
                l = l->next;
            }

            head = head->next;
        }
        r->next = nullptr;
        l->next = right->next;
        
        return left->next;
    }
};