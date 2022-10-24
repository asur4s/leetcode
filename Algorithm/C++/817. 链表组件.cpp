class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet;
        for(auto num: nums){
            numSet.insert(num);
        }
        
        ListNode *cur = head;
        bool inSet = false;
        int ans = 0;

        while(cur != nullptr){
            if(numSet.count(cur->val) != 0){
                if(!inSet){
                    inSet = true;
                    ans++;
                }
            }else{
                inSet = false;
            }
            cur = cur->next;
        }
        return ans;
    }
};
