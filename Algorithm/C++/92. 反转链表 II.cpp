class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }

        ListNode *dummy = new ListNode();
        dummy->next = head;
        int i = 0;

        ListNode *p1, *p2, *p3, *p4;
        p1 = p2 = p3 = p4 = nullptr;
        ListNode *cur, *pre, *back;
        cur = head;
        pre = nullptr;

        while(nullptr != cur){
            i+=1;

            back = cur->next;
            if(i>left && i<=right){
                cur->next = pre;
            }

            if(i == left - 1){
                p1 = cur;
            }
            if(i == left){
                p2 = cur;
            }
            if(i == right){
                p3 = cur;
            }
            if(i == right + 1){
                p4 = cur;
            }

            pre = cur;
            cur = back;
        }

        if (nullptr == p1){
            dummy->next = p3;
        }else{
            p1->next = p3;
        }
        p2->next = p4;

        return dummy->next;
    }
};