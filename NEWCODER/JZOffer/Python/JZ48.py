# /**
#  *
#  * 题目：
#  * 写一个函数，求两个整数之和
#  * 要求在函数体内不得使用+、-、*、/四则运算符号。
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

class Solution:
    def plus(self, pla: int, plb: int):
        """
        python迭代版本，运行成功
        :param pla:
        :param plb:
        :return:
        """
        while plb != 0:
            ta = pla
            pla = pla ^ plb
            plb = ((ta & plb) << 1) & 0xffffffff
        hibit = (pla & 0x80000000) >> 31
        if hibit == 1:
            return -(((~pla) + 1) & 0xffffffff)
        else:
            return pla & 0xffffffff

    def plus_(self, pla: int, plb: int):
        """
        :param pla:
        :param plb:
        :return:
        """
        while plb:
            tmp = ((pla & plb) << 1)& 0xffffffff
            pla ^= plb
            plb = tmp
        hibit = (pla & 0x80000000) >> 31        # 通过第32位符号位判断是否负数 如果是则取反加1再截断  正数则直接截断
        if hibit == 1:
            return -(((~pla) + 1) & 0xffffffff)
        else:
            return pla & 0xffffffff

    def plus__(self, pla: int, plb: int):
        """
        Fixme: 存在错误 负数加法存在：maximum recursion depth exceeded
        :param pla:
        :param plb:
        :return:
        """
        return self.plus__(pla ^ plb, (pla & plb) << 1) if plb else pla


if __name__ == '__main__':
    s = Solution()
    """本题重点，python负数表示与C语言、C++等不同
    Python 中 bin 一个负数，输出的是它的原码的二进制表示加上个负号 -0b11
    在c/c++/java里面负数都是以补码的形式进行存储的
    """
    num1, num2 = eval(input())
    print(s.plus_(num1, num2))
