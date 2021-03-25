/**
 * 
 * 题目：
 * 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
 * 就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，
 * 请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
 * 要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
 * 
 * 示例：
 * 输入：
 * "abcXYZdef",3
 * 输出：
 * "XYZdefabc"
 * 
 */ 

#include<iostream>

using namespace std;

string LeftRotateString(string str, int n) {
    if(str.empty()) return "";
    int size = str.size();
    n = n % size;
    return str.substr(n) + str.substr(0,n);
}

string LeftRotateString_(string str, int n) {
    if(str.empty()) return str;
    n = n % str.size();
    string res = "";
    for(int i=n;i<str.size();i++)
    {
        res += str[i];
    }
    for(int i=0;i<n;i++)
    {
        res += str[i];
    }
    return res;
}

int main()
{
    string str = "XYZdefabc";
    cout << LeftRotateString(str,3) << endl;
    cout << LeftRotateString_(str,3) << endl;
    system("pause");
    return 0;
}