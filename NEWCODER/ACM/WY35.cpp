/*
[题目描述]
如果一个数列S满足对于所有的合法的i,都有S[i + 1] = S[i] + d, 
这里的d也可以是负数和零,我们就称数列S为等差数列。
小易现在有一个长度为n的数列x,小易想把x变为一个等差数列。
小易允许在数列上做交换任意两个位置的数值的操作,并且交换操作允许交换多次。
但是有些数列通过交换还是不能变成等差数列,小易需要判别一个数列是否能通过交换操作变成等差数列

[输入描述]
输入包括两行,第一行包含整数n(2 ≤ n ≤ 50),即数列的长度。 第二行n个元素x[i](0 ≤ x[i] ≤ 1000),即数列中的每个整数。

[输出描述]
如果可以变成等差数列输出"Possible",否则输出"Impossible"。

[示例]
输入：
3
3 1 2
输出：
Possible
*/
#include<iostream>
#include<algorithm>

using namespace std;
/*
解题思路：
先排序，然后看各个相邻元素的差是否一致，如果一致，是等差数列；如果不一致，不是等差数列
*/
int main()
{
    int n;
    while (cin>>n)
    {
        int *arr = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int d = arr[1] - arr[0];
        bool flg = false;
        for(int i=0;i<n-1;i++)
        {
            if((arr[i+1]-arr[i])!=d)
            {
                flg = true;
                break;
            }
        }
        if(flg)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << "Possible" << endl;
        }
    }
    return 0;
}