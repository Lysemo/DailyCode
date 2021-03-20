# /**
#  *
#  * 题目：
#  * 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
#  * 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
#  * 但是对于后面问题他就没辙了。
#  * ACMer希望你们帮帮他,并把问题更加普遍化,
#  * 可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）
#  *
#  * 示例：
#  * 输入：
#  * 13
#  * 输出：
#  * 6
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        # write code here
        num = 0
        for i in range(n + 1):
            tmp = str(i)
            for ix in tmp:
                if ix == '1':
                    num += 1
        return num


if __name__ == '__main__':
    s = Solution()
    lis = eval(input())   # 13
    print(s.NumberOf1Between1AndN_Solution(lis))   # 6
