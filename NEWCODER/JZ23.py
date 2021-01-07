# /**
#  *
#  * 题目：
#  * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
#  * 如果是则返回true,否则返回false。假设输入的数组的任意两个数字都互不相同。
#  *
#  * 示例：
#  * 输入：
#  * [4,8,6,12,16,14,10]
#  * 输出：
#  * true
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

class Solution:
#数组中前面的数字可以分为两部分：
# 第一部分是左子树节点的值，它们都比根节点的值小；
# 第二部分是右子树节点的值，它们都比根节点的值大
    def VerifySquenceOfBST(self, sequence):
        # write code here
        if not sequence:
            return False
        # 找到根节点
        root = sequence[- 1]
        i = 0
        # 找到左子树和右子树
        while i < len(sequence) - 1:
            if sequence[i] > root:
                break
            i += 1
        for j in range(i,len(sequence)-1):
            if sequence[j] < root:
                return False
        left = True
        right = True
        if i > 0:
            left = self.VerifySquenceOfBST(sequence[:i])
        if i < len(sequence) - 1:
            right = self.VerifySquenceOfBST(sequence[i:len(sequence) - 1])
        return left and right


if __name__ == '__main__':
    s = Solution()
    res = eval(input())  # [4,8,6,12,16,14,10]
    print(s.VerifySquenceOfBST(res))    # True
