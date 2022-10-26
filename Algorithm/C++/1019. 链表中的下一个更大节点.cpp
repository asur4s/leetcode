class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int index = 0;
        vector<int> ans;
        stack<pair<int, int>> mystack;
        while(head != nullptr){
            ans.push_back(0);
            while(!mystack.empty() && mystack.top().second < head->val){
                cout<<mystack.top().first<<endl;
                ans[mystack.top().first] = head->val;
                mystack.pop();
            }
            mystack.push({index++, head->val});
            head = head->next;
        }
        return ans;
    }
};