# /**
#  *
#  * 题目：
#  * 输入两个整数序列，第一个序列表示栈的压入顺序，
#  * 请判断第二个序列是否可能为该栈的弹出顺序。
#  * 假设压入栈的所有数字均不相等。
#  * 例如序列1,2,3,4,5是某栈的压入顺序
#  * ，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
#  * 但4,3,5,1,2就不可能是该压栈序列的弹出序列。
#  * （注意：这两个序列的长度是相等的）
#  *
#  * 示例：
#  * 输入：
#  * [1,2,3,4,5],[4,3,5,1,2]
#  * 输出：
#  * false
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  *
#  */

class Solution:
    def IsPopOrder(self, pushV, popV):
        # write code here
        stack=[]
        while popV:
            ##如果stack的最后一个元素与popV中第一个元素相等，将两个元素都弹出
            if stack and stack[-1]==popV[0]:
                stack.pop()
                popV.pop(0)
            # 如果pushV中有数据，压入stack
            elif pushV:
                stack.append(pushV.pop(0))
            # 上面情况都不满足，直接返回false。
            else:
                return False
        return True

if __name__ == '__main__':
    s = Solution()
    pushV,popV = [1,2,3,4,5],[4,3,5,1,2]
    print(s.IsPopOrder(pushV,popV))