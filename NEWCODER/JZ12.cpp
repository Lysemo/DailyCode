/**
 * 
 * 题目：
 * 给定一个double类型的浮点数base和int类型的整数exponent。
 * 求base的exponent次方。
 * 保证base和exponent不同时为0
 * 
 * 示例：
 * 输入：
 * 2，3
 * 输出：
 * 8.000
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 * 
 */

#include<iostream>

using namespace std;

double Power(double base, int exponent) {
    if(base==0) return 0;
    if(exponent==0) return 1;
    int n = exponent;
    if(exponent<0) n = -exponent;
    double ans = 1.0;
    for(int i=1;i<=n;i++){
        ans *= base;
    }
    if(exponent<0) ans = 1/ans;
    return ans;
}

double Power_(double base, int exponent) {
    if(exponent<0){
        base = 1/base;
        exponent = -exponent;
    }
    double res = 1.0;
    for(int i=1;i<=exponent;i++) res *= base;
    return res;
}

double q_power(double b, int n){
    if(n==0) return 1.0;
    double res = q_power(b,n/2);
    if(n&1){
        return res * res * b;
    }
    else
    {
        return res * res;
    }    
}

double Power__(double base, int exponent) {
    if(exponent<0){
        base = 1/base;
        exponent = -exponent;
    }
    return q_power(base,exponent);
}

double Power___(double base, int exponent) {
    if(exponent<0){
        base = 1/base;
        exponent = -exponent;
    }
    double x = base; // 记录x^0, x^1, x^2 ...default=x^1
    double ret = 1.0;// x^0
    while (exponent) {
        if (exponent&1) {
            ret *= x; // 二进制位数是1的，乘进答案。
        }
        x *= x;
        exponent >>= 1;
    }
    return ret;
}

int main(){
    cout << Power(3.0,4) << endl;
    cout << Power_(3.0,4) << endl;
    cout << Power__(3.0,4) << endl;
    cout << Power___(3.0,4) << endl;
    system("pause");
    return 1;
}