class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        int length = 0;
        ListNode *node = head;
        while (node != nullptr){
            length++;
            node = node->next;
        }

        ListNode *dummy = new ListNode(0, head);
        for(int sublen = 1; sublen < length; sublen <<= 1){
            ListNode *pre = dummy, *cur = dummy->next;
            while(cur != nullptr){
                ListNode *head1 = cur;
                for(int i=1; i<sublen && cur->next != nullptr; i++){
                    cur = cur->next;
                }

                ListNode *head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for(int i=1; i<sublen && cur != nullptr && cur->next != nullptr; i++){
                    cur = cur->next;
                }

                ListNode *next = nullptr;
                if(cur != nullptr){
                    next = cur->next;
                    cur->next = nullptr;
                }

                ListNode *merged = merge(head1, head2);
                pre->next = merged;

                while(pre->next != nullptr){
                    pre = pre->next;
                }
                cur = next;
            } 
        }
        return dummy->next;
    }

    ListNode* merge(ListNode *head1, ListNode *head2){
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy, *temp1 = head1, *temp2 = head2;

        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val <= temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1 != nullptr){
            temp->next = temp1;
        }else{
            temp->next = temp2;
        }
        return dummy->next;
    }
};