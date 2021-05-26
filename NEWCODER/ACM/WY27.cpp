/*
[题目描述]
小易有一个圆心在坐标原点的圆，小易知道圆的半径的平方。小易认为在圆上的点而且横纵坐标都是整数的点是优雅的，
小易现在想寻找一个算法计算出优雅的点的个数，请你来帮帮他。
例如：半径的平方如果为25
优雅的点就有：(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)，一共12个点。

[示例]
输入：
25
输出：
12
*/
#include<iostream>
#include<cmath>

using namespace std;

/*
解题思路：
i从0到sqrt(r2),
另一个左边值平方：j2 = r2-i*i
如果sqrt(j2)==int(sqrt(j2)),说明其去根号后整数
num+=4（当i为0/j2为0时，num+=2）

tips:
当x过大时，sqrt(x)可能并不是整数，但当使用float类型保存时，成了整数；
因此，需采用精度更高的double类型来接受sqrt(x)
或者：
不使用变量接收sqrt(x)，
直接进行sqrt(r-i*i)==int(sqrt(r-i*i))判断

float：1bit（符号位）+8bits（指数位)+23bits（尾数位）;  -> 32bit
double：1bit（符号位）+ 11bits（指数位）+ 52bits（尾数位）; -> 64bit
float：2^23 =8388608，共七位，意味着最多能有7位有效数字，但绝对能保证的为6位，也即float的精度为6~7位有效数字；
double：2^52 = 4503599627370496，一共16位，意味着最多能有16位有效数字，但绝对能保证的为15位，也即float的精度为15~16位有效数字。
*/

int main()
{
    int r;
    while(cin>>r)
    {
        int num = 0;
        double tmp;
        for(int i=0;i<=sqrt(r);i++)
        {
            tmp = sqrt(r-i*i);  //sqrt返回值类型为double
            if(tmp==int(tmp))
            // if(sqrt(r-i*i)==int(sqrt(r-i*i)))
            {
                if(i*i==0 || i*i==r)
                {
                    num += 2;
                }
                else
                {
                    num += 4;
                }
            }
        }
        cout << num << endl;
    }
    return 0;
}


// int main() 
// {
//     int n;
//     int x;
//     while (cin>>n)
//     {
//         int count = 0;
//         int r = (int)sqrt(n);
//         if (r*r == n) {
//             count += 4;
//             --r;
//         }
//         for (int i = r; i > 0; i--) 
//         {
//             x = (int)sqrt(n - i*i);
//             if(x*x + i*i == n)
//             {
//                 count += 4;
//             } 
//         }
//         cout<<count<<endl;
//     }
//     return 0;
// }