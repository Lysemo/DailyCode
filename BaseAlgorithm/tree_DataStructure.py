# 树的定义及基础操作实现
# 参考自 https://blog.csdn.net/zzfightingy/article/details/86742755

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    def add(self, item):
        """树结构添加节点"""
        node = TreeNode(item)
        if self.root == None:
            self.root = node
        else:
            # 注意这里是用队列的方式来循环判断当前节点有没有可加入位置的
            queue = []
            queue.append(self.root)
            while queue:
                cur = queue.pop(0)
                if cur.left == None:
                    cur.left = node
                    return
                elif cur.right == None:
                    cur.right = node
                    return
                else:
                    queue.append(cur.left)
                    queue.append(cur.right)
    # 定义深度优先遍历中的先序遍历
    def preorder(self, node):
        if node == None:
            return
        else:
            print(node.val, end = " ")
            self.preorder(node.left)
            self.preorder(node.right)
    # 定义深度优先遍历中的中序遍历
    def inorder(self, node):
        if node == None:
            return
        else:
            self.inorder(node.left)
            print(node.val, end = " ")
            self.inorder(node.right)

    # 定义深度优先遍历中的后序遍历
    def postorder(self, node):
        if node == None:
            return
        else:
            self.postorder(node.left)
            self.postorder(node.right)
            print(node.val, end = " ")

    def breadth_travel(self, root):
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