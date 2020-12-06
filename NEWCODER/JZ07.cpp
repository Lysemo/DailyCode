/**
 * 
 * 题目：
 * 大家都知道斐波那契数列，现在要求输入一个整数n，
 * 请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
 * n<=39
 * 
 * 示例：
 * 输入：
 * 4
 * 输出：
 * 3
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>

using namespace std;

//递归版本
//时间占用627ms | 内存占用584k
int Fibonacci(int n) {
    if(n<2){
        return n;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}

//非递归版本
//时间占用2ms | 内存占用480k
int Fibonacci_(int n) {
    if(n<2){
        return n;
    }
    int pre1 = 0,pre2 = 1;
    int res;
    for(int i=2;i<=n;i++){
        res = pre1 + pre2;
        pre1 = pre2;
        pre2 = res;
    }
    return res;
}

int main(){
    cout << Fibonacci_(4) << endl;
    system("pause");
    return 1;
}