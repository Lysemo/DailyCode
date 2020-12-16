/**
 * 
 * 题目：
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则返回true,否则返回false。假设输入的数组的任意两个数字都互不相同。
 * 
 * 示例：
 * 输入：
 * [4,8,6,12,16,14,10]
 * 输出：
 * true
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool helpV(vector<int> sequence,int start,int root){
    if(start >= root) return true;
    int key = sequence[root];
    int i;
    for(i = start;i<root;i++){
        if(sequence[i]>key)
            break;
    }
    for(int j=i;j<root;j++){
        if(sequence[j]<key)
            return false;
    }
    return helpV(sequence,start,i-1) && helpV(sequence, i, root-1);
}
bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.empty()) return false;
    return helpV(sequence,0,sequence.size()-1);
}

bool VerifySquenceOfBST_(vector<int> sequence) {
    if(sequence.empty()) return false;
    stack<int> roots;
    roots.push(INT16_MIN);
    int max = INT16_MAX;
    for(int i=sequence.size()-1;i>=0;i--){
        if(sequence[i] > max) return false;
        while (sequence[i]<roots.top())
        {
            max = roots.top();
            roots.pop();
        }
        roots.push(sequence[i]);   
    }
    return true;
}

int main(){
    int a[] = {4,8,6,12,16,14,10};
    vector<int> seq(a,a+7);
    cout << VerifySquenceOfBST(seq) << endl;
    cout << VerifySquenceOfBST_(seq) << endl;
    system("pause");
}