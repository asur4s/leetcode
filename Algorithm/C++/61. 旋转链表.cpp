class Solution {
private:
    pair<ListNode*, ListNode*> getHeadTail(ListNode* head, int k){
        ListNode *slow = head, *fast = head, *pre;
        for(int i=0; i<k; i++){
            fast = fast->next;
        }

        while(fast != nullptr){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        return {slow, pre};
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode *tail, *cur;
        int len = 0;
        cur = head;
        while(cur != nullptr){
            len++;
            tail = cur;
            cur = cur->next;
        }
        
        k = k % len;
        if(k == 0){
            return head;
        }

        pair<ListNode*, ListNode*> result = getHeadTail(head, k);
        tail->next = head;
        head = result.first;    
        tail = result.second; // 头节点的前一个

        tail->next = nullptr;
        return head;
    }
};