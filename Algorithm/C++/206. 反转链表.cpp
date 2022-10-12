// 非递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        ListNode *back;

        while(cur != nullptr){
            back = cur->next;
            cur->next = pre;

            pre = cur;
            cur = back;
        }

        return pre;
    }
};

// 递归：后序遍历（由于参数限制，无法使用前序遍历完成）
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};

