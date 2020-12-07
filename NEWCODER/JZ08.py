# /**
#  *
#  * 题目：
#  * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
#  * 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）
#  *
#  * 示例：
#  * 输入：
#  * 1
#  * 输出：
#  * 1
#  * ----
#  * 输入：
#  * 4
#  * 输出：
#  * 5
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

def jumpFloor(number):
    # write code here
    if number <= 1: return number
    pre1, pre2, res = 1, 1, number
    for i in range(2, number + 1):
        res = pre1 + pre2
        pre1 = pre2
        pre2 = res
    return res


if __name__ == '__main__':
    print(jumpFloor(1))
    print(jumpFloor(4))