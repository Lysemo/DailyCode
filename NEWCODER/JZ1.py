# -*- coding:utf-8 -*-

'''
在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数

示例：
输入：
7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
输出：
true

要求：
时间限制：C/C++ 1s,其他语言2秒
空间限制：C/C++ 64M,其他语言128M
'''

def find(target,array):
    flg = len(array[0])
    for i in range(len(array)):
        for j in range(flg):
            if (array[i][j] == target):
                return True
            elif (array[i][j] > target):
                flg = j
                break
    return False

if __name__ == '__main__':
    array = [[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
    target = 7
    print(find(target,array))