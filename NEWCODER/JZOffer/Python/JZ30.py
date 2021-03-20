# /**
#  *
#  * 题目：
#  * 输入一个整型数组，数组里有正数也有负数。
#  * 数组中的一个或连续多个整数组成一个子数组。
#  * 求所有子数组的和的最大值。要求时间复杂度为 O(n).
#  *
#  * 示例：
#  * 输入：
#  * [1,-2,3,10,-4,7,2,-5]
#  * 输出：
#  * 18
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        best_acc = -99999999
        for i in range(len(array)):
            for j in range(i + 1, len(array) + 1):
                best_acc = max(best_acc, sum(array[i:j]))
        return best_acc


if __name__ == '__main__':
    s = Solution()
    lis = eval(input())   # [1,-2,3,10,-4,7,2,-5]
    print(s.FindGreatestSumOfSubArray(lis))   # 18
