// 递归写法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr){
            return list2;
        }else if (list2 == nullptr){
            return list1;
        }else if (list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// 非递归写法：感觉比官方的更优雅一点。
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pHead = new ListNode(-1);  // Without pointer
        ListNode* cur = pHead;

        const int MAX = 101;
        while(list1 != nullptr || list2 != nullptr){
            int value1 = list1 != nullptr ? list1->val : MAX;   /// 101 
            int value2 = list2 != nullptr ? list2->val : MAX;

            if (value1 <= value2){
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        return pHead->next;
    }
};