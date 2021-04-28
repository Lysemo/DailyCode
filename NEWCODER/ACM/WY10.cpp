/**
 * 题目描述：
 * n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，
 * 使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，
 * 问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。
 * 
 * 输入描述：
 * 每个输入包含一个测试用例。每个测试用例的第一行包含一个整数 n（1 <= n <= 100），
 * 接下来的一行包含 n 个整数 ai（1 <= ai <= 100）。
 * 
 * 输出描述：
 * 输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出 -1。
 * 
 * 示例：
 * 输入：
 * 4
 * 7 15 9 5
 * 输出：
 * 3
 * 
 */ 
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

/**
 * 解题思路：
 * 对于平均值以下的奶牛，按苹果数从小到大排序
 * 对于平均值以上的奶牛，按苹果数从大到小排序
 * 对于每个平均值以下的奶牛：
 *      利用贪心思想，先用苹果最多的奶牛给补充，如果不够，再用苹果数次多的，依次类推
 *      直到所有平均数以下的奶牛都达到平均值水平（平均数以上的也达到平均水平了）
 */ 

int main()
{
    int n;
    while (cin>>n)
    {
        int *arr = new int[n];
        stack<int> sta; //用于保存平均值以上的（栈顶到栈底 苹果数从大到小）
        int sumV = 0;   //所有苹果数量
        int num = 0;    //移动此数
        int stop = 0;   //平均数以下的分割界限
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sumV += arr[i];
        }
        int avgV = sumV/n;  //平均苹果数量
        if(sumV%n!=0)   //如果为小数，方案不存在
        {
            cout << -1 << endl;
            return 0;
        }
        sort(arr,arr+n);    //按苹果数量从小到大排序
        for(int i=0;i<n;i++)
        {
            if(arr[i]>avgV) //将平均数以上的加入栈 栈顶为最大的
            {
                sta.push(arr[i]);
            }
            if(arr[i]<avgV) //判断平均数以下的边界
            {
                stop = i;
            }
            if((arr[i]-avgV)%2!=0)  //由于每次只能移动2个苹果，因此，如果与平均数之间的差距不是2的倍数 方案不存在 直接返回
            {
                cout << -1 << endl;
                return 0;
            }
        }
        for(int i=0;i<=stop;i++)    //对平均数以下的奶牛
        {
            int dur = avgV - arr[i];    //计算与平均数的差距
            while (!sta.empty())    //当还有奶牛有多余的苹果时
            {
                if((sta.top()-avgV)>dur)    //如果多余的苹果>差距
                {
                    sta.top() = sta.top() - dur;    //更新苹果多奶牛的苹果数量
                    num += (dur/2); //更新移动次数
                    break;  //不需要其他奶牛补充
                }
                else    //当多余的苹果<=差距
                {
                    dur -= (sta.top()-avgV);    //多余的苹果全拿
                    num += (sta.top()-avgV)/2;  //更新移动次数
                    sta.pop();  //当前奶牛已经没多余苹果了  移除栈
                }
            }
        }
        cout << num << endl; 
    }
    return 0;
}