# /**
#  *
#  * 题目：
#  * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
#  * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
#  * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
#  *
#  * 示例：
#  * 输入：
#  * [[1,2],[3,4]]
#  * 输出：
#  * [1,2,4,3]
#  *
#  * 要求：
#  * 时间限制：C/C++ 1秒，其他语言2秒
#  * 空间限制：C/C++ 64M，其他语言128M
#  */

# 思路：定义四个变量，表示左上和右下的打印范围，一次旋转打印结束后，往对角分别前进和后退一个单位。
# 19ms 5624KB

def printMatrix(matrix):
    # write code here
    rows=len(matrix)
    cols=len(matrix[0])
    result=[]
    if rows==0 and cols==0:
        return result
    left,right,top,bottom = 0,cols-1,0,rows-1        # 四个变量 表示需要打印的矩阵范围

    while left<=right and top<=bottom:
        for i in range(left,right+1):
            result.append(matrix[top][i])
        for i in range(top+1,bottom+1):
            result.append(matrix[i][right])

        if top!=bottom:
            for i in range(right-1,left-1,-1):
                result.append(matrix[bottom][i])
        if left!=right:
            for i in range(bottom-1,top,-1):
                result.append(matrix[i][left])
        left+=1
        right-=1
        top+=1
        bottom-=1
    return result


if __name__ == '__main__':
    lis = [[1,2],[3,4]]
    print(printMatrix(lis))         # 1 2 4 3
