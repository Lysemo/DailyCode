/*
[题目描述]
小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋的包装(包装不可拆分)。 
可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。如果不能购买恰好n个苹果，小易将不会购买。

[输入描述]
输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果

[输出描述]
输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1

[示例]
输入：
20
输出：
3
*/
#include<iostream>

using namespace std;

/*
解题思路：
使用动态规划的思想，dp[i]为购买i个苹果所需的最小包装数
初始化dp[n+1]都为INT_MAX
初始dp[6]=1;dp[8]=1
i=6:n-8
if(dp[i]==INT_MAX)说明此路径不可达，直接跳过
dp[i+6]=min(dp[i+6],dp[i]+1)    从dp[i]通过1步到dp[i+6]
dp[i+8]=min(dp[i+8],dp[i]+1)    从dp[i]通过1步到dp[i+8]
*/

//贪婪算法
//贪婪算法并不一定能得到最优解，但是一个可行的，较好的解；这个题可以得到最优解
int maxPackages(int num) {
    int res = 0;
    int mul, remains;   //除数，余数
    if(num%2 != 0)
    {
        return -1;  //非偶数直接返回
    }
    if (num % 8 == 0)   //如果是8的整倍数，全部给8装
    {
        res += num / 8;
        return res;
    }
    else    //否则，可能存在余数2 4 6三种情况，如果为6，不需要回溯8；如果未4，需要回溯8一次，8+4=12/6=2；如果是2，需要回溯8两次，2+8+8=18/6=3
    {
        mul = num / 8;  //倍数
        remains = num % 8;  //余数 2 | 4 | 6
        res += mul;
        num = num % 8;
        while (mul >= 0) {  //回溯8包装 >=0,说明可回溯
            if (num % 6 == 0) {
                res += num / 6;
                return res;
            }
            else {
                mul--;  //回溯  8包装购买袋数-1
                res--;
                num = num + 8;
            }
        }
    }
    return -1;

}

int main()
{
    int n;
    while (cin>>n)
    {
        int *dp = new int[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=n+1;
        }
        dp[6] = 1;
        dp[8] = 1;
        for(int i=6;i<=n-8;i++)
        {
            if(i==n+1)
            {
                continue;
            }
            dp[i+6] = min(dp[i+6],dp[i]+1);
            dp[i+8] = min(dp[i+8],dp[i]+1);
        }
        if(dp[n]==n+1)
        {
            dp[n]=-1;
        }
        cout << dp[n] << endl;
        cout << maxPackages(n) << endl;
    }
    
    return 0;
}