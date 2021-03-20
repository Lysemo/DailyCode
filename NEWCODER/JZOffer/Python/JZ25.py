# /**
#  *
#  * 题目：
#  * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），
#  * 请对此链表进行深拷贝，并返回拷贝后的头结点。
#  * （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

# -*- coding:utf-8 -*-
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None
        
class Solution:
    # 返回 RandomListNode
    def Clone(self, pHead):
        # write code here
        p1 = pHead
        nodes = []
        d = {}
        while p1:
            nodes.append(p1)
            p1 = p1.next
        p1 = pHead
        while p1:
            if p1.random:
                d[nodes.index(p1)] = nodes.index(p1.random)
            else:
                d[nodes.index(p1)] = -1
            p1 = p1.next
        new_nodes = [RandomListNode(x.label) for x in nodes]
        for i, node in enumerate(new_nodes):
            if i < len(new_nodes) - 1:
                node.next = new_nodes[i + 1]
            if d[i] != -1:
                node.random = new_nodes[d[i]]
        return new_nodes[0] if new_nodes else None
