# /**
#  *
#  * 题目：
#  * 操作给定的二叉树，将其变换为源二叉树的镜像。
#  *
#  * 示例：
#  * 原始：
#  *           8
#  *    	   /  \
#  *    	  6   10
#  *    	 / \  / \
#  *    	5  7 9 11
#  * 镜像：
#  *           8
#  *    	   /  \
#  *    	  10   6
#  *    	 / \  / \
#  *    	11 9 7  5
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


# 非递归方法      18ms 5752KB
def Mirror(root):
    nodeQueue = [root]
    while nodeQueue:
        curNode = nodeQueue.pop(0)
        if not curNode:
            return None
        if curNode.left:
            nodeQueue.append(curNode.left)
        if curNode.right:
            nodeQueue.append(curNode.right)
        curNode.left, curNode.right = curNode.right, curNode.left


# 递归方法   19ms 5752KB
def Mirror_(pRoot):
    if not pRoot:
        return pRoot
    new_right = Mirror_(pRoot.left)
    new_left = Mirror_(pRoot.right)

    pRoot.left = new_left
    pRoot.right = new_right

    return pRoot



def breadth_travel(root):
    """利⽤队列实现树的层次遍历"""
    if root == None:
        return
    queue = []
    queue.append(root)
    while queue:
        node = queue.pop(0)
        print(node.val)
        if node.left is not None:
            queue.append(node.left)
        if node.right != None:
            queue.append(node.right)


if __name__ == '__main__':
    l1 = TreeNode(8)
    l1.left = TreeNode(6)
    l1.right = TreeNode(10)
    l1.left.left = TreeNode(5)
    l1.left.right = TreeNode(7)
    l1.right.left = TreeNode(9)
    l1.right.right = TreeNode(11)

    print(breadth_travel(Mirror_(l1)))     #递归
    print("..........")
    Mirror(l1)             # 非递归
    print(breadth_travel(l1))

