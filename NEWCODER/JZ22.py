# /**
#  *
#  * 题目：
#  * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
#  *
#  * 示例：
#  * 输入：
#  * {5,4,#,3,#,2,#,1}
#  * 输出：
#  * [5,4,3,2,1]
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    def PrintFromTopToBottom(self, root):
        # write code here
        if not root:return ''
        queue = [root]
        res = []
        while queue:
            if queue[0].left:
                queue.append(queue[0].left)
            if queue[0].right:
                queue.append(queue[0].right)
            res.append(queue[0].val)
            queue.pop(0)
        return res

if __name__ == '__main__':
    s = Solution()

    l1 = TreeNode(5)
    l1.left = TreeNode(4)
    l1.left.left = TreeNode(3)
    l1.left.left.left = TreeNode(2)
    l1.left.left.left.left = TreeNode(1)

    print(s.PrintFromTopToBottom(l1))