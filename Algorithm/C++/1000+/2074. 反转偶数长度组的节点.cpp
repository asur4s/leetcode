class Solution{
public:
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        ListNode *cur = head, *curHead = head, *preLast = nullptr;
        int curLen = 0;
        while (cur)
        {
            int len = curLen;
            curHead = cur;
            int actualLen = 0;
            while (len && cur->next)
            {
                cur = cur->next;
                actualLen++;
                len--;
            }
            ListNode *next = cur->next;
            if (actualLen & 1)
            { // 跳了奇数步，对应偶数个点
                cur->next = nullptr;
                ListNode *rHead = reverse(curHead);
                curHead->next = next;
                preLast->next = rHead;
                preLast = curHead;
            }
            else
            {
                preLast = cur;
            }
            cur = next;
            curLen++;
        }
        return head;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *back;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            back = cur->next;
            cur->next = pre;
            pre = cur;
            cur = back;
        }
        return pre;
    }
};