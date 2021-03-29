/**
 * 题目：
 * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
 * 而'*'表示它前面的字符可以出现任意次（包含0次）。 
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 * 
 * 示例：
 * 输入：
 * "aaa","a*a"
 * 输出：
 * true
 * 
 */ 

#include<iostream>
#include<string>

using namespace std;

bool matchCore(string str, string pattern)
{
    if(str[0] == '\0' && pattern[0] == '\0')
        return true;
    if(str[0] != '\0' && pattern[0] == '\0')
        return false;
    if(pattern[1] == '*'){
        if(pattern[0] == str[0] || (pattern[0] == '.' && str[0] != '\0')){
            return matchCore(str.substr(1), pattern.substr(2)) || /* *前面字符出现1次*/
                matchCore(str.substr(1), pattern) || /* *前面字符出现2次*/
                matchCore(str, pattern.substr(2));/* *前面字符出现0次*/
        }
        else{
            return matchCore(str, pattern.substr(2));
        }
    }
    if(pattern[0] == str[0] || (pattern[0] == '.' && str[0] != '\0'))
        return matchCore(str.substr(1), pattern.substr(1));
    return false;
}

bool match(string str, string pattern) {
    // write code here
    if(str.length() == 0 && pattern.length() == 0){
        return true;
    }
    return matchCore(str, pattern);
}

int main()
{
    cout << match("aaa","a*a") << endl;
    system("pause");
    return 0;
}