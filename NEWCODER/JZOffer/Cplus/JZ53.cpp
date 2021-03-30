/**
 * 题目：
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 * 
 * 示例：
 * 输入：
 * "123.45e+6"
 * 输出：
 * true
 * 
 * 输入：
 * "1.2.3"
 * 输出：
 * false
 * 
 */ 
#include<iostream>
#include<string>

using namespace std;

bool isNumeric(string str) 
{
    // write code here
    if(str.empty()) //如果字符串为空，则返回false
    {
        return false;
    }
    int i = 0;
    string pre = "";
    string post = "";
    while(i<str.size()) //按e将字符串分成2段
    {
        if(str[i]=='E' || str[i]=='e')
        {
            break;
        }
        i++;
    }
    if(i==str.size())   //如果没有e，pre=str
    {
        pre = str;
    }
    else    //如果有e，pre为e前半段，post为e后半段
    {
        pre = str.substr(0,i);
        post = str.substr(i+1);
        if(pre.empty()) return false;
        if(post.empty()) return false;
    }
    i = 0;
    if(post[0]=='+' || post[0]=='-')    //如果post第一个字符为'+'/'-'，后面一个字符必须为数字，否则返回false
    {
        if(post[1]>='0' && post[1]<='9')
        {
            i = 1;
        }
        else
        {
            return false;
        }
    }
    while(i<post.size())    //对应post的非第一个字符，其他的必须在0-9之间
    {
        if(post[i]<'0' || post[i]>'9')
            return false;
        i++;
    }
    i = 0;
    int dot = 0;    //统计前半段小数点出现的次数，如果>1,返回false
    if(pre[0]=='+' || pre[0]=='-')  //如果pre第一个字符为'+'/'-'
    {
        if(pre[1]>='0' && pre[1]<='9')  //第二个字符要么为0-9之间
        {
            i = 1;
        }
        else if(pre[1]=='.' && pre[2]>='0' && pre[2]<='9')  //要么为'.'，但第三个字符必须为0-9之间
        {
            i = 1;
        }
        else    //其他的均为false
        {
            return false;
        }
    }
    while(i<pre.size()) //对于除第一个字符的字符，要么在0-9之间，要么为点，且点出现的次数只能为1次
    {
        if(pre[i]=='.') //如果为点，dot++，如果>1，之间返回false
        {
            dot++;
            i++;
            if(dot>1)
            {
                return false;
            }
            continue;
        }
        if(pre[i]<'0' || pre[i]>'9') return false;  //如果在0-9之外，false
        i++;
    }
    return true;
}

int main()
{
    cout << isNumeric("12.4E-152") << endl;
    system("pause");
    return 0;
}