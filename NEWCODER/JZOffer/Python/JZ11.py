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
        n = n & 0xffffffff        # 在Python里面需要将负数和0xffffffff进行与操作，来去掉负数前面的负号，可以理解为超过32位的东西就不进行考虑
    return bin(n).count("1")


def NumberOf1_(n):
    # write code here
    if n < 0:
        n = n & 0xffffffff   # python和别的语言存储负数的格式有点区别
    temp = 0x00000001
    count = 0
    for i in range(64):
        if n & temp:
            count = count + 1
        temp = temp << 1
    return count


if __name__ == '__main__':
    """本题重点，python负数表示与C语言、C++等不同
        Python 中 bin 一个负数，输出的是它的原码的二进制表示加上个负号 -0b11
        在c/c++/java里面负数都是以补码的形式进行存储的
    """
    print(NumberOf1(10))
    print(NumberOf1(-10))