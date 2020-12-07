# /**
#  *
#  * 题目：
#  * 输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示
#  *
#  * 示例：
#  * 输入：
#  * 10
#  * 输出：
#  * 2
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */
def NumberOf1(n):
    # write code here
    if n < 0:
        n = n & 0xffffffff            #补码运算
    return bin(n).count("1")


if __name__ == '__main__':
    print(NumberOf1(10))
    print(NumberOf1(-10))