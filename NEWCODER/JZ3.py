# -*- coding:utf-8 -*-

'''
题目：
输入一个链表，按链表从尾到头的顺序返回一个ArrayList

示例：
输入：
{67,0,24,58}
输出：
[58,24,0,67]

要求：
C/C++ 1秒，其他语言2秒
空间限制：C/C++ 64M，其他语言128M
'''

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def printListFromTailToHead(listNode):
    # 注意判空操作
    if (listNode == None):
        return []
    vals = []
    while (listNode != None):
        vals.append(listNode.val)
        listNode = listNode.next
    for i in range(int(len(vals) / 2)):
        tmp = vals[i]
        vals[i] = vals[len(vals) - 1 - i]
        vals[len(vals) - 1 - i] = tmp
    return vals

if __name__ == '__main__':
    listNode = ListNode(1)
    p = listNode
    p.next = ListNode(2)
    p = p.next
    p.next = ListNode(3)
    p = p.next
    p.next = ListNode(4)
    newList = printListFromTailToHead(listNode)
    print(newList)

