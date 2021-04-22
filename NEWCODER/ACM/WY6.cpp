/**
 * 题目描述：
 * 有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
 * 要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
 * 
 * 输入描述：
 * 每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，
 * 接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。
 * 接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
 * 
 * 输出描述：
 * 输出一行表示最大的乘积。
 * 
 * 示例：
 * 输入：
 * 3
 * 7 4 7
 * 2 50
 * 输出：
 * 49
 */ 
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int *arr = new int[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];    //为方便对应 数组从1开始
        }
        int k,d;
        cin>>k>>d;
        //dpmax[k][i]为选k个元素，以第i个元素结尾的乘积最大值，包含第i个元素
        long long **dpmax = new long long*[k+1];    //用于存以第i个元素结尾 选择k个人 元素的最大乘积
        long long **dpmin = new long long*[k+1];    //用于存以第i个元素结尾 选择k个人 元素的最小乘积
        long long ans = 0;
        for(int i=0;i<=k;i++)
        {
            dpmax[i] = new long long[n+1];
            dpmin[i] = new long long[n+1];
            for(int j=0;j<=n;j++)
            {
                dpmax[i][j] = dpmin[i][j] = 0;  //初始化为0
            }
        }
        int kk;
        for(int i=1;i<=n;i++)
        {
            dpmax[1][i] = dpmin[1][i] = arr[i]; //因为第i个必选，因此选择1个人 以第i个元素结尾的 最大 最小乘积为本身
            for(kk=2;kk<=k;kk++)    //其余的k-1个人 选择，从2开始 到k
            {
                for(int j=i-1;j>0 && i-j<=d;j--)    //k-1个人只能从i的前面选，且如果第i个元素选，下一个元素与i的间隔不能超过d
                {   
                    //选kk个人，以第i个元素结尾的最大乘积 = 
                    //如果第i个元素为负，则在前i-1人选择的为最小乘积
                    //如果第i个元素为正，则在前i-1人选择的为最大乘积
                    //把 选择kk-1个人，以第j个元素结尾的最大值 一直更新到dpmax[kk][i]
                    //因为j靠前的 不一定比j靠后的 最大乘积大，因此最大值也需跟dpmax[kk][i]相比
                    //dpmax[kk][i]里面存的是 j靠后的最大值
                    dpmax[kk][i] = max({dpmax[kk][i],dpmax[kk-1][j]*arr[i],dpmin[kk-1][j]*arr[i]});
                    //选kk个人，以第i个元素结尾的最小乘积 = 
                    //如果第i个元素为负，则在前i-1人选择的为最大乘积
                    //如果第i个元素为正，则在前i-1人选择的为最小乘积
                    dpmin[kk][i] = min({dpmin[kk][i],dpmax[kk-1][j]*arr[i],dpmin[kk-1][j]*arr[i]});
                }
            }
            //选择k个人 以第i个元素结尾的最大值 一直更新到ans上，
            //因为不一定以第i个元素结尾的选择 就是最大的
            ans = max(ans,dpmax[k][i]); 
        }
        cout << ans << endl;
    }
    return 0;
}