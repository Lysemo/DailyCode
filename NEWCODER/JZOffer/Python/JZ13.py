# /**
#  *
#  * 题目：
#  * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
#  * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
#  * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */
def reOrderArray(array):
    """
    TimeComplex o(n), SpaceComplex o(n),
    :param array:
    :return: list
    """
    # write code here
    pre = []
    tal = []
    for i in array:
        if i % 2 == 0:
            pre.append(i)
        else:
            tal.append(i)
    return tal + pre


def reOrderArray_(array):
    """
    TimeComplex o(n), SpaceComplex o(1),
    :param array:
    :return: list
    """
    # write code here
    n = len(array)
    i = 0
    while i < n:
        if array[i] % 2 == 1:
            i += 1
        else:
            array.append(array[i])
            del (array[i])
            n -= 1
    return array


if __name__ == '__main__':
    # print(reOrderArray([1, 2, 3, 4, 5, 6, 7, 8]))
    print(reOrderArray_([1, 2, 3, 4, 5, 6, 7, 8]))