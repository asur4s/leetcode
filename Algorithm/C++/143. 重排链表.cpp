class Solution {
public:
    ListNode* findMiddle(ListNode *head){
        ListNode *fast;
        fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            head = head->next;
        }
        return head;
    }
    ListNode* reverseList(ListNode *head){
        ListNode *pre, *cur, *back;
        pre = nullptr;
        cur = head;

        while(cur != nullptr){
            back = cur->next;
            cur->next = pre;

            pre = cur;
            cur = back;
        }
        return pre;
    }
    ListNode* mergeList(ListNode *list1, ListNode *list2){
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        ListNode *cur, *back;
        cur = new ListNode();
        back = cur;
        
        while(list1 != nullptr || list2 != nullptr){
            if(list1 != nullptr){
                cur->next = list1;
                cur = cur->next;
                list1 = list1->next;
            }
            if(list2 != nullptr){
                cur->next = list2;
                cur = cur->next;
                list2 = list2->next;
            }
        }
        return back->next;
    }
    void reorderList(ListNode *head) {
        if(head->next == nullptr){
            return;
        }

        ListNode *back = findMiddle(head);
        ListNode *middle;
        middle = back->next;

        back->next = nullptr;
        middle = reverseList(middle);

        mergeList(head, middle);
    }
};