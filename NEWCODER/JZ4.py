# -*- coding:utf-8 -*-

'''
题目：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回

示例：
输入：
[1,2,3,4,5,6,7],[3,2,4,1,6,5,7]
输出：
{1,2,5,3,4,6,7}

要求：
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 64M，其他语言128M
'''

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def reConstructBinaryTree(pre, tin):
    # write code here
    if(len(tin)==0):
        return None
    if(len(tin)==1):
        return TreeNode(tin[0])
    for i in range(len(tin)):
        if (tin[i] == pre[0]):
            break
    for j in range(len(pre)):
        if pre[j] not in tin[:i+1]:
            break
    if(j==len(pre)-1):
        j = len(pre)
    root = TreeNode(tin[i])
    root.left = reConstructBinaryTree(pre[1:j], tin[:i])
    root.right = reConstructBinaryTree(pre[j:], tin[i + 1:])
    return root

if __name__ == '__main__':
    pre = [1,2,4,3,5,6]
    tin = [4,2,1,5,3,6]
    root = reConstructBinaryTree(pre,tin)