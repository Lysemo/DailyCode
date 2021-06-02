/*
[题目描述]
如果一个01串任意两个相邻位置的字符都是不一样的,我们就叫这个01串为交错01串。例如: "1","10101","0101010"都是交错01串。
小易现在有一个01串s,小易想找出一个最长的连续子串,并且这个子串是一个交错01串。小易需要你帮帮忙求出最长的这样的子串的长度是多少。

[输入描述]
输入包括字符串s,s的长度length(1 ≤ length ≤ 50),字符串中只包含'0'和'1'

[输出描述]
输出一个整数,表示最长的满足要求的子串长度。

[示例]
输入：
111101111
输出：
3
*/
#include<iostream>
#include<string>

using namespace std;
/*
解题思路：
遍历一遍字符串，统计最长的交错字符串
初始num为1
如果相邻的两个不相等，num+1，如何num跟maxnum比较，如果大于，跟新maxnum；
如果相邻的两个相等，说明上一个交错字符串已经结束，初始化新的一个交错字符串num=1；
最后，输出最长的交错字符串的长度
*/
int main()
{
    string s;
    while (cin>>s)
    {
        int maxNum = 1;
        int num = 1;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                num += 1;
                if(num>maxNum)
                {
                    maxNum = num;
                }
            }
            else
            {
                num = 1;
            }
        }
        cout << maxNum << endl;
    }
    
    return 0;
}