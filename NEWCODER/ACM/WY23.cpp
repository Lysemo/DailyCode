/**
 * 题目描述：
 * 小易邀请你玩一个数字游戏，小易给你一系列的整数。你们俩使用这些整数玩游戏。
 * 每次小易会任意说一个数字出来，然后你需要从这一系列数字中选取一部分出来让它们的和等于小易所说的数字。
 *  例如： 如果{2,1,2,7}是你有的一系列数，小易说的数字是11.你可以得到方案2+2+7 = 11.如果顽皮的小易想坑你，
 * 他说的数字是6，那么你没有办法拼凑出和为6 现在小易给你n个数，让你找出无法从n个数中选取部分求和的数字中的最小数（从1开始）。
 * 
 * 输入描述：
 * 输入第一行为数字个数n (n ≤ 20)
 * 第二行为n个数xi (1 ≤ xi ≤ 100000)
 * 
 * 输出描述：
 * 输出最小不能由n个数选取求和组成的数
 * 
 * 示例：
 * 输入：
 * 3
 * 5 1 2
 * 输出：
 * 4
 */ 

#include<iostream>
#include<algorithm>

using namespace std;

/*
解题思想：
基于这样一种迭代的思想：
我当前假如说可以得到最大的数为k，
则再来一个新的数字p，若p<=k+1，则我可以得到的最大的数为p+k，
若p>k+1，则会出现空挡，k+1就肯定不能再得到
eg：1 1 此时最大为2
新来一个数 1 ->最大为3； 2 -> 最大为4； 3-> 最大为5；  4-> 不能得到3，出现断层
*/
int main()
{
    int n;
    while (cin>>n)
    {
        int *arr = new int[n];
        int miss = 0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            if(arr[i]>miss+1)
            {
                break;
            }
            miss += arr[i];
        }
        cout << miss+1 << endl;
    }
    
    return 0;
}