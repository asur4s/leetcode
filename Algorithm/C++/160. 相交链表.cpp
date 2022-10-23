class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA, *pB;
        pA = headA;
        pB = headB;

        while(pA != pB){
            if(pA == NULL){
                pA = headB;
            }else{
                pA = pA->next;
            }
            if(pB == NULL){
                pB = headA;
            }else{
                pB = pB->next;
            }
        }
        return pA;
    }
};