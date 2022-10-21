class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr){
            return nullptr;
        }

        ListNode *dummy = new ListNode();
        dummy->next = head;
        int i;

        ListNode* fast = dummy;
        for(i=0; i<=n; i++){ // 多走一步，让指针指到删除节点的前一个。
            fast = fast->next;
        }
        ListNode* slow = dummy;
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy->next;
    }
};