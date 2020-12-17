/**
 * 
 * 题目：
 * 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
 * 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
 * 但是对于后面问题他就没辙了。
 * ACMer希望你们帮帮他,并把问题更加普遍化,
 * 可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）
 * 
 * 示例：
 * 输入：
 * 13
 * 输出：
 * 6
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int NumberOf1Between1AndN_Solution(int n){
    int digit=1, res = 0;
    int high= n / 10, cur = n % 10, low = 0;
    while (high!=0 or cur!=0)
    {
        if(cur==0) res += high*digit;
        else if(cur==1) res += high*digit+low+1;
        else res += (high+1)*digit;
        low += cur*digit;
        cur = high % 10;
        high = high / 10;
        digit *=10;
    }
    return res;
}

int main(){
    int num = NumberOf1Between1AndN_Solution(55);
    cout << num << endl;
    system("pause");
    return 1;
}