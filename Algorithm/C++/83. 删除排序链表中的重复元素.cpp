// 非递归：效率更高、内存消耗更高
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(nullptr == head || nullptr == head->next){
            return head;
        }
        ListNode *cur, *back;
        cur = head;
        back = head->next;

        while(nullptr != cur && nullptr != cur->next){
            while(nullptr != back && cur->val == back->val){
                back = back->next;
            }
            
            cur->next = back;
            cur = back;
        }

        return head;
    }
};

// 官方题解：最容易理解
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(nullptr == head){
            return head;
        }

        ListNode* cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            else {
                cur = cur->next;
            }
        }

        return head;
    }
};

// 递归写法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(nullptr == head || nullptr == head->next){
            return head;
        }

        ListNode *next;
        next = head->next;
        while(nullptr != next && next->val == head ->val){
            next = next->next;
        }

        head->next = deleteDuplicates(next);
        return head;
    }
};