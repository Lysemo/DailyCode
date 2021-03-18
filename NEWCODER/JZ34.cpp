/**
 * 
 * 题目：
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中
 * 找到第一个只出现一次的字符,并返回它的位置, 
 * 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
 * 
 * 示例：
 * 输入：
 * "google"
 * 输出：
 * 4
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<string>
#include<map>
#include<bitset>

using namespace std;

int FirstNotRepeatingChar(string str) {
    for(int i=0;i<str.size();i++){
        int cnt=0;
        for(int j=0;j<str.size();j++){
            if(str[j]==str[i]){
                cnt++;
            }
            if(cnt>=2) break;
        }
        if(cnt==1) return i;
    }
    return -1;
}

int FirstNotRepeatingChar_(string str){
    int mp[128] = {0};
    for(const char ch : str){
        mp[ch]++;
    }
    for(int i=0;i<str.size();i++){
        if(mp[str[i]]==1) return i;
    }
    return -1;
}

int FirstNotRepeatingChar__(string str){
    map<char,int> mp;
    for(const char ch : str){
        mp[ch]++;
    }
    for(int i=0;i<str.size();i++){
        if(mp[str[i]]==1) return i;
    }
    return -1;
}

int FirstNotRepeatingChar___(string str){
    bitset<128> b1,b2;
    for(const char ch : str){
        if(!b1[ch] && !b2[ch]){
            b1[ch] = 1;
        }
        else if(b1[ch] && !b2[ch]){
            b2[ch] = 1;
        }
    }
    for(int i=0;i<str.size();i++){
        if(b1[str[i]] && !b2[str[i]]) return i;
    }
    return -1;
}

int main(){
    string s = "google";
    cout << FirstNotRepeatingChar(s) << endl;
    cout << FirstNotRepeatingChar_(s) << endl;
    cout << FirstNotRepeatingChar__(s) << endl;
    cout << FirstNotRepeatingChar___(s) << endl;
    system("pause");
    return 1;
}