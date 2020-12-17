/**
 * 
 * 题目：
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 * 例如输入字符串abc,则按字典序打印出由字符a,b,c
 * 所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 * 描述：输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
 * 
 * 示例：
 * 输入：
 * "ab"
 * 输出：
 * ["ab","ba"]
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

void lis(char s, string str,set<string> &ret,string &ex){
    if(str.size()==1){
        ex += str;
        ret.insert(ex);
        ex.erase(ex.end()-1);
        return;
    }
    int len = str.size();
    for(int i=0;i<len;i++){
        char s = str[i];
        string tmp = str;
        ex += s;
        lis(s,tmp.erase(i,1),ret,ex);
        ex.erase(ex.end()-1);
    } 
}

vector<string> Permutation(string str) {
    vector<string> ret;
    set<string> tret;
    string ex;
    if(str.empty()) return ret;
    if(str.size()==1) {ret.push_back(str); return ret;}
    int len = str.size();
    for(int i=0;i<len;i++){
        char s = str[i];
        string tmp = str;
        ex += s;
        lis(s,tmp.erase(i,1),tret,ex);
        ex.erase(ex.end()-1);
    }
    for(set<string>::iterator it = tret.begin();it!=tret.end();it++){
        ret.push_back(*it);
    }
    return ret;
}

void perm(int pos, string s, set<string> &ret) {
    if(pos+1 == s.size()){
        ret.insert(s);
        return;
    }
    for(int i=pos;i<s.size();i++){
        swap(s[pos],s[i]);
        perm(pos+1,s,ret);
        swap(s[pos],s[i]);
    }
}

vector<string> Permutation_(string str) {
    if(str.empty()) return {};
    set<string> ret;
    perm(0,str,ret);
    return vector<string>({ret.begin(),ret.end()});
}

int main(){
    string s = "aa";
    vector<string> ret1 = Permutation(s);
    vector<string> ret2 = Permutation_(s);
    for(int i=0;i<ret1.size();i++){
        cout << ret1[i] << endl;
    }
    for(int i=0;i<ret2.size();i++){
        cout << ret2[i] << endl;
    }
    system("pause");
    return 1;
}