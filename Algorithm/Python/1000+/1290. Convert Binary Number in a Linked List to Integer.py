class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        result = 0
        while head != None:
            result += head.val
            if head.next == None:
                break
            else:
                result *= 2
                head = head.next
        return result

# better
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        num = head.val
        while head.next:
            num = num * 2 + head.next.val
            head = head.next
        return num
