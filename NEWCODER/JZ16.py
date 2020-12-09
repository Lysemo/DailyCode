# /**
#  *
#  * 题目：
#  * 输入两个单调递增的链表，输出两个链表合成后的链表，
#  * 当然我们需要合成后的链表满足单调不减规则
#  *
#  * 示例：
#  * 输入：
#  * {1,3,5},{2,4,6}
#  * 输出：
#  * {1,2,3,4,5,6}
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# 29ms 6900kB 递归
def Merge(l1, l2):
    if not l1 or not l2:
        return l1 or l2
    if l1.val < l2.val:
        l1.next = Merge(l1.next, l2)
        return l1
    else:
        l2.next = Merge(l1, l2.next)
        return l2


# 17ms 2956kB 非递归版本
def Merge_(l1, l2):
    dummy = cur = ListNode(0)
    while l1 and l2:
        if l1.val < l2.val:
            cur.next = l1
            l1 = l1.next
        else:
            cur.next = l2
            l2 = l2.next
        cur = cur.next
    cur.next = l1 or l2
    return dummy.next


# example
if __name__ == '__main__':
    l1 = ListNode(1)
    l1.next = ListNode(3)
    l1.next.next = ListNode(5)
    l2 = ListNode(2)
    l2.next = ListNode(4)
    l2.next.next = ListNode(6)
    result = Merge_(l1,l2)
    while result:
        print(result.val)                        # 1,2,3,4,5,6
        result = result.next