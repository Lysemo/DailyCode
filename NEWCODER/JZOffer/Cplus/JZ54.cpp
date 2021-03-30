/**
 * 题目：
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。
 * 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
 * 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 * 
 * 输出描述：如果当前字符流没有存在出现一次的字符，返回#字符。
 * 
 */

#include<string>
#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

string str = "";
void Insert(char ch) {
        str += ch;
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce() {
    if(str.empty()) return '#';
    unordered_map<char,int> mp;
    for(int i=0;i<str.size();i++)
    {
        mp[str[i]]++;
    }
    for(int i=0;i<str.size();i++)
    {
        if(mp[str[i]]==1)
        {
            return str[i];
        }
    }
    return '#';
}

int charCnt[128];
queue<int> que;

void Insert_(char ch) 
{
    if(charCnt[ch]++ ==0)
    {
        que.push(ch);
    }
}

char FirstAppearingOnce_(){
    while (!que.empty())
    {
        char ch = que.front();
        if(charCnt[ch]==1)
        {
            return ch;
        }
        else
        {
            que.pop();
        }
        
    }
    return '#';
}

int main()
{
    Insert('g');
    Insert('o');
    Insert('o');
    Insert('g');
    Insert('e');
    cout << FirstAppearingOnce() << endl;
    Insert_('g');
    Insert_('o');
    Insert_('o');
    Insert_('g');
    Insert_('e');
    cout << FirstAppearingOnce_() << endl;
    system("pause");
    return 0;
}