/**
 * 题目描述：
 * 牛牛拿到了一个藏宝图，顺着藏宝图的指示，牛牛发现了一个藏宝盒，藏宝盒上有一个机关，
 * 机关每次会显示两个字符串 s 和 t，根据古老的传说，牛牛需要每次都回答 t 是否是 s 的子序列。
 * 注意，子序列不要求在原字符串中是连续的，例如串 abc，它的子序列就有 {空串, a, b, c, ab, ac, bc, abc} 8 种。
 * 
 * 输入描述：
 * 每个输入包含一个测试用例。每个测试用例包含两行长度不超过 10 的不包含空格的可见 ASCII 字符串。
 * 
 * 输出描述：
 * 输出一行 “Yes” 或者 “No” 表示结果。
 * 
 * 示例：
 * 输入：
 * x.nowcoder.com
 * ooo
 * 输出：
 * Yes
 */ 

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s,t;
    while (cin>>s>>t)
    {
        if(t.size()==0) //空串 是 任何字符串的子串
        {
            cout << "Yes" << endl;
            return 0;
        }
        if(s.size()==0) //s为空时，t就不是s的子串（能到这，说明t不为空）
        {
            cout << "No" << endl;
            return 0;
        } 
        int ti = 0; //定义t字符串的初始索引
        for(int i=0;i<s.size();i++) //对s字符串进行遍历
        {
            if(s[i]==t[ti]) //如果s一个字符等于t一个字符
            {
                ti++;   //ti向后移动
                if(ti>=t.size())    //如果ti>=size了，说明t是s的子串，输出，提前结束
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        cout << "No" << endl;   //如果跑到这，说明t不是s子串
    }
    return 0;
}