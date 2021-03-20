/**
 * 
 * 题目：
 * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
 * 例如6、8都是丑数，但14不是，因为它包含质因子7。 
 * 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数
 * 
 * 示例：
 * 输入：
 * 7
 * 输出：
 * 8
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int GetUglyNumber_Solution(int index) {
    if(index<=0) return 0;
    vector<int> uglyList = {1};
    int p2=0,p3=0,p5=0;
    for(int i=0;i<index-1;i++){
        int newUgly = min(uglyList[p2]*2,uglyList[p3]*3);
        newUgly = min(newUgly,uglyList[p5]*5);
        uglyList.push_back(newUgly);
        if(newUgly%2==0) p2+=1;
        if(newUgly%3==0) p3+=1;
        if(newUgly%5==0) p5+=1;
    }
    return uglyList[uglyList.size()-1];
}

int main(){
    int n = GetUglyNumber_Solution(1500);
    cout << n << endl;
    system("pause");
    return 1;
}