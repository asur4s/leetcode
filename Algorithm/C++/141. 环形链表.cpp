// 快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(NULL == head){
            return NULL;
        }

         ListNode *fast;
         fast = head;

         while(head != NULL){
             
             head = head->next;
             if(fast->next != NULL && fast->next->next != NULL){
                 fast = fast->next->next;
             }else{
                 return false;
             }

             if(head == fast){
                 return true;
             }
         }

         return false;
    }
};