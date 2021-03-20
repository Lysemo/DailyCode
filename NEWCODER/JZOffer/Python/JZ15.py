# /**
#  *
#  * 题目：
#  * 输入一个链表，反转链表后，输出新链表的表头。
#  * 示例：
#  * 输入：
#  * {1,2,3}
#  * 输出：
#  * {3,2,1}
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def ReverseList(pHead):
    # write code here
    if pHead == None or pHead.next == None:
        return pHead
    pre = None
    cur = pHead
    while cur != None:
        tmp = cur.next
        cur.next = pre
        pre = cur
        cur = tmp
    return pre