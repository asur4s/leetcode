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

// better
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int sum = head->val;
        while(head->next != NULL){
            sum = sum * 2 + head->next->val;
            head = head->next;
        }
        return sum;
    }
};
