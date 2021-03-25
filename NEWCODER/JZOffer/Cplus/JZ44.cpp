/**
 * 题目：
 * 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
 * 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
 * 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
 * 正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
 * 
 * 示例：
 * 输入：
 * "nowcoder. a am I"
 * 输出：
 * "I am a nowcoder."
 * 
 */ 

#include<iostream>
#include<vector>

using namespace std;

string ReverseSentence(string str)
{
    if(str.empty()) return str;
    vector<string> tmp;
    int i=0,j=0;
    while(true)
    {
        //可以过滤多余的空格
        if(str[j]=='\0')
        {
            tmp.push_back(str.substr(i,j-i));
            break;
        }
        if(str[j]!=' ')
        {
            j++;
        }
        else{
            tmp.push_back(str.substr(i,j-i));
            i = j+1;
            j++;
        }
    }
    if(tmp.empty()) return str;    //说明全是空格，直接返回原字符串
    string res = "";
    for(int i=tmp.size()-1;i>0;i--)
    {
        res += tmp[i];
        res += " ";
    }
    res += tmp[0];
    return res;
}

int main()
{
    cout << ReverseSentence("nowcoder. a am I") << endl;
    system("pause");
    return 0;
}