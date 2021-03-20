/**
 *
 * 题目：
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？ 
 * 
 * 示例：
 * 输入：
 * 4
 * 输出：
 * 5
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */

#include<iostream>

using namespace std;

//时间占用2ms | 内存占用484k
int rectCover(int number) {
    if(number<=2) return number;
    int pre1=1,pre2=1,res;
    for(int i=3;i<=number;i++){
        res = pre1 + pre2;
        pre1 = pre2;
        pre2 = res;
    }
    return res;
}

int main(){
    cout << rectCover(4) << endl;
    system("pause");
    return 1;
}