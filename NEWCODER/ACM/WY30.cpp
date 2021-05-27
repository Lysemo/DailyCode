/*
[题目描述]
对于一个整数X，定义操作rev(X)为将X按数位翻转过来，并且去除掉前导0。例如:
如果 X = 123，则rev(X) = 321;
如果 X = 100，则rev(X) = 1.
现在给出整数x和y,要求rev(rev(x) + rev(y))为多少？

[输入描述]
输入为一行，x、y(1 ≤ x、y ≤ 1000)，以空格隔开。

[输出描述]
输出rev(rev(x) + rev(y))的值

[示例]
输入：
123 100
输出：
223
*/
#include<iostream>
#include<string>

using namespace std;

int rev(int x)
{   //使用字符串的翻转实现
    string xs = to_string(x);
    int n = xs.size();
    for(int i=0;i<n/2;i++)
    {
        char tmp = xs[i];
        xs[i] = xs[n-i-1];
        xs[n-i-1] = tmp;
    }
    return atoi(xs.c_str());
}

int rev1(int x)
{   //使用整除取余实现
    int t = 0;
    while (x!=0)
    {
        t = 10*t + x%10;    //x%10为x的最后一位，x/10去掉最后一位，循环下去，把x的每个数字 从右向左 都取出来，然后递乘10，先取出来的为最高位
        x = x/10;
    }
    return t;
}

int main()
{
    int X,Y;
    while (cin>>X>>Y)
    {
        cout << rev(rev(X)+rev(Y)) << endl;
        cout << rev1(rev1(X)+rev1(Y)) << endl;
    }  
}