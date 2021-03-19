# /**
#  *
#  * 题目：
#  * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
#  * 例如6、8都是丑数，但14不是，因为它包含质因子7。
#  * 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数
#  *
#  * 示例：
#  * 输入：
#  * 7
#  * 输出：
#  * 8
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

# -*- coding:utf-8 -*-
class Solution:
    def GetUglyNumber_Solution(self, index):
        # write code here
        if index <= 0:
            return 0
        uglyList = [1]
        p2, p3, p5 = 0, 0, 0
        for i in range(index - 1):
            newUgly = min(uglyList[p2] * 2, uglyList[p3] * 3, uglyList[p5] * 5)
            uglyList.append(newUgly)
            if (newUgly % 2 == 0):
                p2 += 1
            if (newUgly % 3 == 0):
                p3 += 1
            if (newUgly % 5 == 0):
                p5 += 1
        return uglyList[-1]


if __name__ == '__main__':
    s = Solution()
    lis = eval(input())   # 7
    print(s.GetUglyNumber_Solution(lis))   # 8
