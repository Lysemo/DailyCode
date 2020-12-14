/**
 * 
 * 题目：
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）
 * 
 * 示例：
 * 输入：
 * 1
 * 输出：
 * 1
 * ----
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

//递归版本
//时间占用246ms | 内存占用496k
int jumpFloor(int number) {
    if(number<3){
        return number;
    }
    return jumpFloor(number-1)+jumpFloor((number-2));
}

//非递归版本
//时间占用3ms | 内存占用484k
int jumpFloor_(int number) {
    if(number<3){
        return number;
    }
    int pre1 = 1,pre2 = 2;
    int res;
    for(int i=3;i<=number;i++){
        res = pre1 + pre2;
        pre1 = pre2;
        pre2 = res;
    }
    return res;
}

int main(){
    cout << jumpFloor(4) << endl;
    cout << jumpFloor_(4) << endl;
    system("pause");
    return 1;
}
