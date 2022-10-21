class Solution {
private:
    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode *tail){
        ListNode *back;
        ListNode *pre = tail->next;
        ListNode *cur = head;
        while(pre != tail){
            back = cur->next;
            cur->next = pre;
            pre = cur;
            cur = back;
        }
        return {tail, head};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *pre = dummy, *cur = head, *tail, *nex;
        int i;

        while(cur){
            tail = pre;
            for(i=0; i<k; i++){
                tail = tail->next;
                if(!tail){
                    return dummy->next;
                }
            }
            nex = tail->next;

            pair<ListNode*, ListNode*> result = reverse(cur, tail);
            cur = result.first;
            tail = result.second;
            pre->next = cur;
            tail->next = nex;
            
            pre = tail;
            cur = tail->next;
        }
        return dummy->next;
    }
};