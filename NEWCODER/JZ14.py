# /**
#  *
#  * 题目：
#  * 输入一个链表，输出该链表中倒数第k个结点。
#  * 示例：
#  * 输入：
#  * 1,{1,2,3,4,5}
#  * 输出：
#  * {5}
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def FindKthToTail(head, k):
    """
    遍历全部链表，并保存
    TimeComplex o(n), SpaceComplex o(n)
    :param head:
    :param k:
    :return:
    """
    # write code here
    ans = []
    if head == None:
        return None
    else:
        while (head.next != None):
            ans.append(head)
            head = head.next
        ans.append(head)
    if k > len(ans) or k < 1:
        return None
    return ans[-k]


def FindKthToTail_(head, k):
    """
    双指针遍历
    TimeComplex o(n), SpaceComplex o(1)
    :param head:
    :param k:
    :return:
    """
    # write code here
    slow, fast = head, head
    for i in range(k):
        if not fast:
            return None
        fast = fast.next
    while fast:
        slow = slow.next
        fast = fast.next
    return slow


if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    head.next.next.next.next.next = None

    # print(FindKthToTail([1, 2, 3, 4, 5, 6, 7, 8]))
    # print(FindKthToTail(head,2).val)
    print(FindKthToTail_(head, 2).val)