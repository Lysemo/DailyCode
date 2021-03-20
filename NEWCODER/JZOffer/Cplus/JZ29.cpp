/**
 * 
 * 题目：
 * 输入n个整数，找出其中最小的K个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，
 * 则最小的4个数字是1,2,3,4
 * 
 * 示例：
 * 输入：
 * [4,5,1,6,2,7,3,8],4
 * 输出：
 * [1,2,3,4]
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 * 
 */ 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> ret;
    if(k==0 || k>input.size()) return ret;
    sort(input.begin(),input.end(),less<int>());
    return vector<int>({input.begin(),input.begin()+k});
}

int parti(vector<int> &input,int l,int r){
    int pivot = input[r-1];
    int i = l;
    for(int j=l;j<r-1;j++){
        if(input[j]<pivot){
            swap(input[i++],input[j]);
        }
    }
    swap(input[i],input[r-1]);
    return i;
}

vector<int> GetLeastNumbers_Solution_(vector<int> input, int k) {
    vector<int> res;
    if(k==0 || k>input.size()) return res;
    int l=0,r = input.size();
    while (l<r)
    {
        int p = parti(input,l,r);
        if(p+1 ==k){
            return vector<int>({input.begin(),input.begin()+k});
        }
        if(p+1<k){
            l = p + 1;
        }
        else
        {
            r = p;
        }   
    }
    return res;
    
}

int main(){
    int a[] = {4,5,1,6,2,7,3,8};
    vector<int> input(a,a+8);
    vector<int> res = GetLeastNumbers_Solution(input,4);
    vector<int> res1 = GetLeastNumbers_Solution_(input,4);
    for(const int v:res){
        cout << v << " ";
    }
    cout << " " << endl;
    for(const int v:res1){
        cout << v << " ";
    }
    system("pause");
    return 1;
}