# /**
#  *
#  * 题目：
#  * 大家都知道斐波那契数列，现在要求输入一个整数n，
#  * 请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
#  * n<=39
#  *
#  * 示例：
#  * 输入：
#  * 4
#  * 输出：
#  * 3
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

def Fibonacci(n):
    # write code here
    if n <= 1: return n
    pre1, pre2, res = 0, 1, n
    for i in range(2, n + 1):
        res = pre1 + pre2
        pre1 = pre2
        pre2 = res
    return res


if __name__ == '__main__':
    n = 4
    print(Fibonacci(n))