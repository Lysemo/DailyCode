# /**
#  *
#  * 题目：
#  * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
#  * 例如输入字符串abc,则按字典序打印出由字符a,b,c
#  * 所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
#  * 描述：输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
#  *
#  * 示例：
#  * 输入：
#  * "ab"
#  * 输出：
#  * ["ab","ba"]
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

import itertools
# 借用python迭代器
class Solution:
    def Permutation(self, ss):
        # write code here
        if len(ss) ==0:
            return ss
        ans = []
        for i in itertools.permutations(ss, len(ss)):
            tmp = ''.join(i)
            if tmp not in ans:
                ans.append(tmp)
        return ans

if __name__ == '__main__':
    s = Solution()
    strs = eval(input())   # "ab"
    print(s.Permutation(strs))     # ['ab', 'ba']
