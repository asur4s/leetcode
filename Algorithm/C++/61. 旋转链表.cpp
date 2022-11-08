class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *dummy = new ListNode(0, head);

        ListNode *cur = dummy;
        int len = 0;
        while(cur->next != nullptr){
            len += 1;
            cur = cur->next;
        }
        k = k % len;

        if(k == 0){
            return head;
        }else{
            cur->next = head;
        }

        for(int i=0; i<len-k; i++){
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;

        delete dummy;
        return head;
    }
};