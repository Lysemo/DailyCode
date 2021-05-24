/**
 * 题目描述：
 * 考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 
 * 1.根据字符串的字典序排序。例如：
 * "car" < "carriage" < "cats" < "doggies < "koala"
 * 2.根据字符串的长度排序。例如：
 * "car" < "cats" < "koala" < "doggies" < "carriage"
 * 考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
 * 
 * 输入描述：
 * 输入第一行为字符串个数n(n ≤ 100)
 * 接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
 * 
 * 输出描述：
 * 如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
 * 如果根据长度排列而不是字典序排列输出"lengths",
 * 如果两种方式都符合输出"both"，否则输出"none"
 * 
 * 示例：
 * 输入：
 * 3
 * a
 * aa
 * bbb
 * 输出：
 * both
 */ 
#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    while (cin>>n)
    {
        string *ss = new string[n];
        for(int i=0;i<n;i++)
        {
            cin>>ss[i];
        }
        bool flg1 = true;
        bool flg2 = true;
        for(int i=1;i<n;i++)
        {
            if(ss[i].size()<=ss[i-1].size())    //每个字符串跟前面一个字符串相比，如果有一个字符串比它前面字符串的长度小于/等于，说明它不是按长度排序的
            {
                flg1 = false;
            }
            if(ss[i]<=ss[i-1])  //string类 重载了< > <= >=等运算符，比较的默认是ascii码值，如果有一个比前面的小/等于，说明不是按照字典序列排序
            {
                flg2 = false;
            }
        }
        if(flg1 && flg2)
        {
            cout << "both" << endl;
        }
        else if(flg1)
        {
            cout << "lengths" << endl;
        }
        else if(flg2)
        {
            cout << "lexicographically" << endl;
        }
        else
        {
            cout << "none" << endl;
        }
        
    }
    return 0;
}