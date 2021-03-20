/**
 * 
 * 题目：
 * 输入一个整型数组，数组里有正数也有负数。
 * 数组中的一个或连续多个整数组成一个子数组。
 * 求所有子数组的和的最大值。要求时间复杂度为 O(n).
 * 
 * 示例：
 * 输入：
 * [1,-2,3,10,-4,7,2,-5]
 * 输出：
 * 18
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
    if(array.empty()) return 0;
    vector<int> index;
    int maxV = INT16_MIN;
    for(int i=0;i<array.size();i++){
        if(array[i]>maxV) maxV = array[i];
        if(array[i]<0){
            index.push_back(i);
        }
    }
    int l = 0, r = array.size()-1;
    for(const int v:index){
        int cur=0;
        int next = 0;
        for(int i=l;i<=v;i++){
            cur += array[i];
        }
        for(int i=v;i<r;i++){
            next += array[i];
        }
        if(next<=0) r = v-1;
        if(cur<=0 && v+1<array.size()) l = v+1;
    }
    int sum = 0;
    for(int i=l;i<=r;i++){
        sum += array[i];
    }
    if(l>r) return maxV;
    else return sum;
}

int FindGreatestSumOfSubArray_(vector<int> array) {
    int sz = array.size();
    vector<int> dp(sz+1,1);
    dp[0] = 0;
    int res = array[0];
    for(int i=1;i<=sz;i++){
        dp[i] = max(array[i-1],dp[i-1]+array[i-1]);
        res = max(res,dp[i]);
    }
    return res;
}

int FindGreatestSumOfSubArray__(vector<int> array) {
    int res = array[0];
    int tmp = 0;
    int maxV = INT16_MIN;
    for(const int k:array){
        if(k>maxV) maxV = k;
        if(tmp+k<0){
            tmp = 0;
        }
        else
        {
            tmp += k;
        }
        res = max(res,tmp);
    }
    if(tmp!=0) return res;
    return maxV;
}

int main(){
    int a[] = {1,-2,3,10,-4,7,2,-5};
    vector<int> arr(a,a+8);
    cout << FindGreatestSumOfSubArray(arr) << endl;
    cout << FindGreatestSumOfSubArray_(arr) << endl;
    cout << FindGreatestSumOfSubArray__(arr) << endl;
    system("pause");
    return 1;
}