# /**
#  *
#  * 题目：
#  * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
#  * 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
#  * 则打印出这三个数字能排成的最小数字为321323
#  *
#  * 示例：
#  * 输入：
#  * [3,32,321]
#  * 输出：
#  * "321323"
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

# -*- coding:utf-8 -*-

import itertools
class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        min_sum = '999999999999999'
        for tmp in itertools.permutations(numbers):
            ans = ''
            for i in tmp:
                ans += str(i)
            min_sum = min(min_sum, ans)
        return min_sum


if __name__ == '__main__':
    s = Solution()
    lis = eval(input())   # [3,32,321]
    print(str(s.PrintMinNumber(lis)))   # 321323


