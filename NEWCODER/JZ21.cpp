/**
 * 
 * 题目：
 * 输入两个整数序列，第一个序列表示栈的压入顺序，
 * 请判断第二个序列是否可能为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。
 * 例如序列1,2,3,4,5是某栈的压入顺序
 * ，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
 * 但4,3,5,1,2就不可能是该压栈序列的弹出序列。
 * （注意：这两个序列的长度是相等的）
 * 
 * 示例：
 * 输入：
 * [1,2,3,4,5],[4,3,5,1,2]
 * 输出：
 * false
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 * 
 */ 

#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int> pushV,vector<int> popV,int popleft,int popright){
    vector<int> index;
    for(int i=popleft;i<=popright;i++){
        for(int j=0;j<pushV.size();j++){
            if(popV[i]==pushV[j]){
                index.push_back(j);
                break;
            } 
        }
    }
    if(index[1]<index[0] && index[2]>index[1]) return false;
    else return true;
}
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if(pushV.empty()) return false;
    if(pushV.size()==1){
        if(pushV[0]==popV[0]) return true;
        else return false;
    }
    if(pushV.size()==2){
        if(pushV[0]==popV[0] && pushV[1]==popV[1]) return true;
        if(pushV[0]==popV[1] && pushV[1]==popV[0]) return true;
        return false;
    }
    for(int i=0;i<popV.size()-2;i++){
        bool flg = check(pushV, popV, i, i+2);
        if(!flg) return false;
    }
    return true;
}

int main(){
    int a[] = {1,2,3,4,5};
    vector<int> pushV(a,a+5);
    int b[] = {4,5,3,2,1};
    vector<int> popV(b,b+5);
    cout << IsPopOrder(pushV,popV) << endl;
    system("pause");
    return 1;
}