/**
 * 题目描述：
 * 牛牛想尝试一些新的料理，每个料理需要一些不同的材料，问完成所有的料理需要准备多少种不同的材料。
 * 
 * 输入描述：
 * 每个输入包含 1 个测试用例。每个测试用例的第 i 行，表示完成第 i 件料理需要哪些材料，
 * 各个材料用空格隔开，输入只包含大写英文字母和空格，输入文件不超过 50 行，每一行不超过 50 个字符。
 * 
 * 输出描述：
 * 输出一行一个数字表示完成所有料理需要多少种不同的材料。
 * 
 * 示例：
 * 输入：
 * BUTTER FLOUR
 * HONEY FLOUR EGG
 * 输出：
 * 4
 */ 
#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

/**
 * 解题思路：
 * set去重；
 * 由于不知道输入多少行，因此用while(cin>>str)不断获取输入，直到用户手动停止；
 * windows按ctrl+c结束输入循环；linux按ctrl+d结束输入循环
 * 每遇到一个空格或回车，为变量赋一次值，执行一次循环里面的语句
 */ 

int main()
{
    string str;
    unordered_set<string> s;
    while (cin>>str)
    {
        s.insert(str);
    }
    cout << s.size() << endl;
    system("pause");
    return 0;
}