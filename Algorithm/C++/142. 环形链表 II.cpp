class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }

        ListNode *fast, *ptr;
        fast = ptr = head;

        while(head != NULL){
            head = head->next;
            if(fast->next != NULL && fast->next->next != NULL){
                fast = fast->next->next;
            }else{
                return NULL;
            }

            if(fast == head){
                while(ptr != head){
                    ptr = ptr->next;
                    head = head->next;
                }
                return ptr;
            }
        }

        return NULL;
    }
};