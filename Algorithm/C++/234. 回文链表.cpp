class Solution {
public:
    ListNode* findMiddle(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* fast;
        fast = head;

        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            head = head->next;
        }
        return head;
    }

    ListNode* reverseList(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

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

    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr){
            return true;
        }

        ListNode *back = findMiddle(head);
        ListNode *middle = back->next;
        back->next = nullptr;

        middle = reverseList(middle);
        // len of left list > len of right list
        while(middle != nullptr){
            if(middle->val == head->val){
                head = head->next;
                middle = middle->next;
            }else{
                return false;
            }
        }

        return true;
    }
};