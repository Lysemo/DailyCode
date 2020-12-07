# /**
#  *
#  * 题目：
#  * 给定一个double类型的浮点数base和int类型的整数exponent。
#  * 求base的exponent次方。
#  * 保证base和exponent不同时为0
#  *
#  * 示例：
#  * 输入：
#  * 2，3
#  * 输出：
#  * 8.000
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  *
#  */
def Power(base, exponent):
    """
    :param base: double
    :param exponent: int
    :return: base^exponent
    """
    # write code here
    if exponent<0:
        base = 1/base
        exponent = -exponent
    ans =1.0
    while exponent:
        if exponent&1:
            ans *= base
        base *=base
        exponent >>=1
    return ans


if __name__ == '__main__':
    print(Power(2,3))