# /**
#  *
#  * 题目：
#  * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
#  * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def zhongxu(self,root):
        if not root:
            return []
        return self.zhongxu(root.left)+[root]+self.zhongxu(root.right)
    def Convert(self, pRootOfTree):
        # write code here
        list1=self.zhongxu(pRootOfTree)
        if len(list1)==0:
            return None
        if len(list1)==1:
            return pRootOfTree
        for i in range(len(list1)-1):
            list1[i].right=list1[i+1]
            list1[i+1].left=list1[i]
        return list1[0]
