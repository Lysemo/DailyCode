# /**
#  *
#  * 题目：
#  * 输入n个整数，找出其中最小的K个数。
#  * 例如输入4,5,1,6,2,7,3,8这8个数字，
#  * 则最小的4个数字是1,2,3,4
#  *
#  * 示例：
#  * 输入：
#  * [4,5,1,6,2,7,3,8],4
#  * 输出：
#  * [1,2,3,4]
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  *
#  */

class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        tinput = sorted(tinput)
        if k > len(tinput):
            return []
        return tinput[:k]


if __name__ == '__main__':
    s = Solution()
    lis, key = eval(input())   # [4,5,1,6,2,7,3,8],4
    print(s.GetLeastNumbers_Solution(lis,key))   # [1, 2, 3, 4]
