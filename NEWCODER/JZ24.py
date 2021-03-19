# /**
#  *
#  * 题目：
#  * 输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。
#  * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
#  *
#  * 示例：
#  * 输入：
#  * {10,5,12,4,7},22
#  * 输出：
#  * [[10,5,7],[10,12]]
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

# 递归解法
class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        result = []
        if root == None:
            return result
        self.sums = expectNumber
        self.DFS(root, result, [root.val])
        return result
    def DFS(self, root, result, path):
        if root.left == None and root.right == None and sum(path) == self.sums:
            result.append(path)
        if root.left != None:
            self.DFS(root.left, result, path+[root.left.val])
        if root.right != None: self.DFS(root.right, result, path+[root.right.val])

# 非递归解法
class Solution_:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        if root == None:
            return []
        result = []
        stack = []
        stack.append((root, [root.val]))
        while stack:
            node, path = stack.pop()
            if node.left == None and node.right == None and sum(path) == expectNumber:
                result.append(path)
            if node.right != None:
                stack.append((node.right, path + [node.right.val]))
            if node.left != None:
                stack.append((node.left, path + [node.left.val]))
        return result

if __name__ == '__main__':
    s = Solution()
    # s = Solution_()
    l1 = TreeNode(10)
    l1.left = TreeNode(5)
    l1.right = TreeNode(12)
    l1.left.left = TreeNode(4)
    l1.left.right = TreeNode(7)
    target = 22
    print(s.FindPath(l1,target))