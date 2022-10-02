class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        while(head != NULL){
            sum += head->val;
            if(head->next == NULL){
                break;
            }else{
                sum *= 2;
                head = head->next;
            }
        }
        return sum;
    }
};