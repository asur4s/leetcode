class Solution {
private:
    ListNode* mergeTwoList(ListNode* a, ListNode* b){
        if(!a || !b){
            return a? a:b;
        }
        ListNode head, *tail = &head, *a_ptr = a, *b_ptr = b;
        while(a_ptr && b_ptr){
            if(a_ptr->val < b_ptr->val){
                tail->next = a_ptr;
                a_ptr = a_ptr->next;
            }else{
                tail->next = b_ptr;
                b_ptr = b_ptr->next;
            }
            tail = tail->next;
        }
        tail->next = a_ptr? a_ptr:b_ptr;
        return head.next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l == r){
            return lists[l];
        }
        if(l > r){
            return nullptr;
        }
        int middle = (l + r) / 2;
        return mergeTwoList(merge(lists, l, middle), merge(lists, middle+1, r));
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        return merge(lists, 0, lists.size() - 1);
    }
};