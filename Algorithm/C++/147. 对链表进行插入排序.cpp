class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *last = head;
        ListNode *cur = head->next;
        ListNode *temp;

        while(cur != nullptr){
            if(cur->val >= last->val){
                last = last->next;
            }else{
                temp = dummy;
                while(temp->next->val < cur->val){
                    temp = temp->next;
                }
                last->next = cur->next;
                cur->next = temp->next;
                temp->next = cur;
                
            }
            cur = last->next;
        }

        return dummy->next;
    }
};