/**
 * 题目描述：
 * 牛牛的作业薄上有一个长度为 n 的排列 A，这个排列包含了从1到n的n个数，但是因为一些原因，
 * 其中有一些位置（不超过 10 个）看不清了，但是牛牛记得这个数列顺序对的数量是 k，
 * 顺序对是指满足 i < j 且 A[i] < A[j] 的对数，请帮助牛牛计算出，符合这个要求的合法排列的数目。
 * 
 * 输入描述：
 * 每个输入包含一个测试用例。每个测试用例的第一行包含两个整数 n 和 k（1 <= n <= 100, 0 <= k <= 1000000000），
 * 接下来的 1 行，包含 n 个数字表示排列 A，其中等于0的项表示看不清的位置（不超过 10 个）。
 * 
 * 输出描述：
 * 输出一行表示合法的排列数目。
 * 
 * 示例：
 * 输入：
 * 5 5
 * 4 0 0 2 0
 * 输出：
 * 2
 */
 
#include<iostream>
#include<vector>

using namespace std;

int cnt = 0;

bool judge(int *arr,int n,int k)    //计算数组的顺序对 数量
{
    int num = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                num++;
            }
        }
    }
    if(num==k)
    {
        return true;
    }
    return false;
}

void func(int *arr,int l,int n,vector<int> &index,vector<int> &val,bool *mark,int k)
{
    if(l==index.size()) //全排列完成
    {
        if(judge(arr,n,k))  //判断这种排列的顺序对数是不是==k，如果是，cnt++
        {
            cnt++;
        }
    }
    else
    {
        for(int i=0;i<val.size();i++)   //对每一个看不见的数
        {
            if(!mark[i])    //如果第i个数 没有被安排
            {
                mark[i] = true; //改标志
                arr[index[l]] = val[i]; //为原始数组相应位置赋值
                func(arr,l+1,n,index,val,mark,k);   //递归
                arr[index[l]] = 0;  //状态恢复
                mark[i] = false;    //状态恢复
            }
        }
    }
}

int main()
{
    int n,k;
    while (cin>>n>>k)
    {
        int *arr = new int[n];  //记录原始数组
        int *num = new int[n+1];    //记录1-n n个数，那个数出现了，那个数看不见了
        vector<int> index;  //记录看不见数的位置索引
        vector<int> value;  //记录看不见的数都是哪几个
        for(int i=1;i<=n;i++)   //默认都看不见
        {
            num[i] = 0;
        }
        for(int i=0;i<n;i++)    //输入数据
        {
            cin>>arr[i];
            if(arr[i]==0)   //如果==0，说明看不见
            {
                index.push_back(i); //将该位置 加到 索引数组中
            }
            else
            {
                num[arr[i]] = 1;    //能看见，num对应位置 置1
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(num[i] == 0) //当看不见的数 挑出来
            {
                value.push_back(i);
            }
        }
        bool *mark = new bool[value.size()];    //标记数组
        for(int i=0;i<value.size();i++)
        {
            mark[i] = false;
        }
        func(arr,0,n,index,value,mark,k);   //利用递归来实现序列的全排列
        cout << cnt << endl;
    }
    return 0;
}