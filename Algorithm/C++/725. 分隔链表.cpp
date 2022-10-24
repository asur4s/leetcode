class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode *cur = head;
        while(cur != nullptr){
            n++;
            cur = cur->next;
        }

        int i, p, q, total;
        p = n / k;
        q = n % k;

        vector<ListNode *> parts;
        ListNode *part = head;
        ListNode *backup;
        for(i=0; i<k; i++){
            parts.push_back(part);

            total = p + (i<q?1:0);
            while(total > 1){
                total--;
                part = part->next;
            }
            if(part != nullptr){
                backup = part->next;
                part->next = nullptr;
                part = backup;
            }
        }
        return parts;
    }
};