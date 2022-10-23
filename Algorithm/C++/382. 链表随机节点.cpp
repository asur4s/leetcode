class Solution {
private:
    ListNode *_head;
public:
    Solution(ListNode* head) {
        _head = head;
    }
    
    int getRandom() {
        int i = 1;
        int ans;
        ListNode *cur = _head;
        while(cur != nullptr){
            if(rand() % i == 0){
                ans = cur->val;
            }
            cur = cur->next;
            i++;
        }
        return ans;
    }
};