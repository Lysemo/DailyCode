/**
 * 题目：
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
 * 数值为0或者字符串不是一个合法的数值则返回0
 * 输入描述：
 * 输入一个字符串,包括数字字母符号,可以为空
 * 输出描述：
 * 如果是合法的数值表达则返回该数字，否则返回0
 * 
 * 示例：
 * 输入：
 * "+2147483647"
 * 输出：
 * 2147483647
 * 
 * 输入：
 * "1a33"
 * 输出：
 * 0
 * 
 */ 
#include<iostream>
#include<cmath>

using namespace std;

int StrToInt(string str) 
{
    if(str.empty()) //如果字符串为空，即非法输入，返回0
    {
        return 0;
    }
    int i = 0;  //默认字符串第一位为数字
    int n = 0;  //数字通过权值累加得到
    if(str[i]=='+' || str[i]=='-')  //如果字符串前一位为‘+’或‘-’，则数字开始位置为1
    {
        i = 1;
    }
    for(;i<str.size();i++)  //遍历每一位数字
    {
        if(str[i]<48 || str[i]>57)  //‘0’-‘9’ ascii码为 48-57  如果没在则个之间，说明为非法字符，直接return 0
        {
            return 0;
        }
        //n += (str[i]-48)*pow(10,str.size()-1-i);    // n = n + 10^(sz-1-i)  因为前面为高位
        n = n*10 + (str[i]-'0');    //每次乘10加个位，可以累乘到最高位
    }
    return str[0]=='-'?-n:n;    //判断是否为负数，如果是，取反
}

//当字符串转数字时，需要考虑是否溢出的问题
int StrToInt_(string str)
{
    //int 最大值：2147483647 | 最小值：-2147483648
    if(str.empty()) return 0;
    int isNegtive = 1, overValue = 0;   //负数标志位和溢出标志位
    int digit = 0, value = 0;
    int idx = 0;
    if(str[0]=='-')
    {
        isNegtive = -1; //标志位置为-1，之后每次都是负数相加
        idx = 1;
    }
    else if(str[0]=='+')
    {
        idx = 1;
    }
    for(;idx<str.size();idx++)
    {
        if(str[idx]<'0' || str[idx]>'9')  //非法字符返回0 
        {
            return 0;
        }
        digit = str[idx]-'0';   //先找到个位数字
        //计算溢出标准 当<0时，未溢出；当>0时，溢出
        //当前值-INT_MAX/10，如果<0,肯定不溢出；如果>0，肯定溢出
        //                  如果=0，可能溢出，可能不溢出，取决于下次加的个位
        //                  负数如果>8，溢出；正数如果>7溢出；
        //判断接下来会不会溢出
        overValue = isNegtive*value - INT_MAX/10 + 
                ( ((isNegtive+1)/2+digit>8)?1:0 );
        if(overValue>0) return 0;   //大于0，则溢出，返回0
        value = value*10 + isNegtive*digit; //上次结果*10+新一次的个位
    }
    return value;
}

int main()
{  
    cout << StrToInt("-15652") << endl;
    cout << StrToInt_("-15652") << endl;
    system("pause");
    return 0;
}