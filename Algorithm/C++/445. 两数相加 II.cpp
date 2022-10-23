class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1 != nullptr){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *ans = nullptr;
        int carry = 0;
        int a, b, c, value;
        while(!s1.empty() || !s2.empty() || carry != 0){
            if(s1.empty()){
                a = 0;
            }else{
                a = s1.top();
                s1.pop();
            }
            if(s2.empty()){
                b = 0;
            }else{
                b = s2.top();
                s2.pop();
            }
            c = a + b + carry;
            carry = c / 10;
            value = c % 10;
            ListNode *node = new ListNode(value);
            node->next = ans;
            ans = node;
        }
        return ans;
    }
};