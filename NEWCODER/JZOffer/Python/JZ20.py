# /**
#  *
#  * 题目：
#  * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */
# -*- coding:utf-8 -*-
# 辅助栈，记录目前的最小值。
# 每次进行push操作，辅助栈中要压入当前数据栈中最小数字。
# 进行pop操作时，辅助栈弹出栈底数字。
# 进行min操作时，得到辅助栈栈底数字。

class Solution:
    def __init__(self):
        self.stack = []    #数据栈
        self.assist = []   #辅助栈
    def push(self, node):
        # write code here
        self.stack.append(node)
        if len(self.assist)==0 or node<=self.assist[-1]:
            self.assist.append(node)
        else:
            self.assist.append(self.assist[-1])
    def pop(self):
        # write code here
        if self.stack:
            self.assist.pop()
            return self.stack.pop()
    def top(self):
        # write code here
        if self.stack:
            return self.stack[-1]
    def min(self):
        # write code here
        if self.assist:
            return self.assist[-1]


if __name__ == '__main__':
    s = Solution()
    s.push(4)
    print(s.stack)
    s.push(2)
    print(s.stack)
    s.push(3)
    print(s.stack)
    s.push(1)
    print(s.stack)
    s.pop()
    print(s.stack)
    print(s.min())
