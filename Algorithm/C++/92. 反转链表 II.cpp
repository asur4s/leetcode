// 一趟扫描
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }

        ListNode *dummy = new ListNode();
        dummy->next = head;
        int i = 0;

        ListNode *p1, *p2, *p3, *p4;
        p1 = p2 = p3 = p4 = nullptr;
        ListNode *cur, *pre, *back;
        cur = head;
        pre = nullptr;

        while(nullptr != cur){
            i+=1;

            back = cur->next;
            if(i>left && i<=right){
                cur->next = pre;
            }

            if(i == left - 1){
                p1 = cur;
            }
            if(i == left){
                p2 = cur;
            }
            if(i == right){
                p3 = cur;
            }
            if(i == right + 1){
                p4 = cur;
            }

            pre = cur;
            cur = back;
        }

        if (nullptr == p1){
            dummy->next = p3;
        }else{
            p1->next = p3;
        }
        p2->next = p4;

        return dummy->next;
    }
};

// 两趟扫描
class Solution {
private:
    pair<ListNode*, ListNode*> reverseList(ListNode *head, ListNode *tail){
        ListNode *back;
        ListNode *pre = tail->next;
        ListNode *cur = head;
        while(pre != tail){
            back = cur->next;
            cur->next = pre;
            pre = cur;
            cur = back;
        }
        return {tail, head};
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }

        ListNode *dummy = new ListNode();
        dummy->next = head;
        int i = -1;

        ListNode *cur=dummy;
        ListNode *p1, *p2, *p3, *p4;
        while(cur){
            i++;
            if(i == left-1){
                p1 = cur;
            }
            if(i == left){
                p2 = cur;
            }
            if(i == right){
                p3 = cur;
            }
            if(i == right+1){
                p4 = cur;
                break;
            }
            cur = cur->next;
        }

        pair<ListNode*, ListNode*> result = reverseList(p2, p3);
        p2 = result.first;
        p3 = result.second;

        p1->next = p2;
        p3->next = p4;

        return dummy->next;
    }
};