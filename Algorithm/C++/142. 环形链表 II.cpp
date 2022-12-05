class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        ListNode *fast=head, *slow=head;
        while(slow != nullptr){
            slow = slow->next;
            if(fast != nullptr && fast->next != nullptr){
                fast = fast->next->next;
            }else{
                slow = nullptr;
                break;
            }
            if(slow == fast){
                while(head != slow){
                    head = head->next;
                    slow = slow->next;
                }
                break;
            }
        }
        return slow;
    }
};