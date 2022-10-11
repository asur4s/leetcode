// 非递归
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(nullptr == head || nullptr == head->next){
            return head;
        }
        ListNode *cur, *back;
        cur = head;
        back = head->next;

        while(nullptr != cur && nullptr != cur->next){
            while(nullptr != back && cur->val == back->val){
                back = back->next;
            }
            
            cur->next = back;
            cur = back;
        }

        return head;
    }
};