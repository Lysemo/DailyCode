# /**
#  *
#  * 题目：
#  * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
#  * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
#  * 由于数字2在数组中出现了5次，超过数组长度的一半，
#  * 因此输出2。如果不存在则输出0。
#  *
#  * 示例：
#  * 输入：
#  * [1,2,3,2,2,2,5,4,2]
#  * 输出：
#  * 2
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        for i in numbers:
            if numbers.count(i) > len(numbers)//2:
                return i
        return 0

if __name__ == '__main__':
    s = Solution()
    lis = eval(input())   # [1,2,3,2,2,2,5,4,2]
    print(s.MoreThanHalfNum_Solution(lis))   # 2
