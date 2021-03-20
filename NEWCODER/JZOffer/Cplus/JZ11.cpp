/**
 * 
 * 题目：
 * 输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示
 * 
 * 示例：
 * 输入：
 * 10
 * 输出：
 * 2
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>

using namespace std;

//时间占用4ms | 内存占用360k
int  NumberOf1(int n) {
    vector<int> num(32,0);
    int c = -n;
    int index = 0;
    if(n==-2147483648){
        return 1;
    }
    if(n<0){
        num[num.size()-1] = 1;
        c = n*(-1);
    }
    while(c!=0){
        num[index] = c%2;
        c = c/2;
        index ++;
    }
    if(n<0){
        num[0] = num[0] ^ 1;
        num[0] = num[0] + 1;
        int flg = num[0]/2;
        num[0] = num[0]%2;
        for(int i=1;i<num.size()-1;i++){
            num[i] = num[i] ^ 1;
            num[i] = num[i] + flg;
            flg = num[i]/2;
            num[i] = num[i]%2;
        }
    }
    int count = 0;
    for(int i=0;i<num.size();i++)
        count = count + (num[i] ^ 0);
    return count;
}

int  NumberOf1_(int n) {
    int mark = 0x01;
    int ans = 0;
    while (mark!=0)
    {
        if(mark & n) ans++;
        mark <<= 1;
    }
    return ans;
}

int  NumberOf1__(int n) {
    int ans = 0;
    while (n!=0)
    {
        ans++;
        n = n & (n-1);
    }
    return ans;
}

int main(){
    int n = -2147483648;
    cout << NumberOf1(-2147483648) << endl;
    cout << NumberOf1_(-11) << endl;
    cout << NumberOf1__(-2147483648) << endl;
    system("pause");
    return 1;
}