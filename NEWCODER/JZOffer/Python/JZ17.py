# /**
#  *
#  * 题目：
#  * 输入两棵二叉树A，B，判断B是不是A的子结构。
#  * （ps：我们约定空树不是任意一个树的子结构）
#  *
#  * 示例：
#  * 输入：
#  * {8,8,#,9,#,2,#,5},{8,9,#,2}
#  * 输出：
#  * true
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


def HasSubtree(pRoot1, pRoot2):
    # write code here
    result = False
    if pRoot1 and pRoot2:
        if pRoot1.val == pRoot2.val:
            result = same(pRoot1, pRoot2)
        if not result:
            result = HasSubtree(pRoot1.left, pRoot2)
        if not result:
            result = HasSubtree(pRoot1.right, pRoot2)
    return result


def same(p1, p2):
    if not p2:
        return True
    if not p1:
        return False
    return p1.val == p2.val and same(p1.left,p2.left) and same(p1.right,p2.right)


# example
if __name__ == '__main__':
    l1 = TreeNode(8)
    l1.left = TreeNode(8)
    l1.left.left = TreeNode(9)
    l1.left.left.left = TreeNode(2)
    l1.left.left.left.left = TreeNode(5)

    l2 = TreeNode(8)
    l2.left = TreeNode(9)
    l2.left.left = TreeNode(2)

    result = HasSubtree(l1,l2)
    print(result)                       # True



