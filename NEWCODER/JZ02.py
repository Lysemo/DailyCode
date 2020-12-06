# -*- coding:utf-8 -*-

'''
题目：
请实现一个函数，将一个字符串中的每个空格替换成“%20”

示例：
输入：
We Are Happy
输出：
We%20Are%20Happy

要求：
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32M，其他语言64M
'''


def replaceSpace(s):
    res = ''
    for i in range(len(s)):
        if (s[i]) == ' ':
            res = res + '%20'
        else:
            res = res + s[i]
    return res

if __name__ == '__main__':
    s = 'We Are Happy'
    res = replaceSpace(s)
    print(res)