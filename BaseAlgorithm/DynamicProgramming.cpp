#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//问题：有1，3，5分面额的硬币，给定一个面值n，问组成给定面值所需的最少硬币数量？？？
//返回组成面值n所需的最少硬币数量
//递归带存储 解法
int func11(int n,int dp[])
{
    if(dp[n]>0)
    {
        return dp[n];
    }
    if(n==1 || n==3 || n==5)
    {
        dp[n] = 1;
        return 1;
    }
    else if (n==2 || n==4)
    {
        dp[n] = 2;
        return 2;
    }
    else
    {
        int n1 = func11(n-1,dp) + 1;
        int n3 = func11(n-3,dp) + 1;
        int n5 = func11(n-5,dp) + 1;
        dp[n] = min({n1,n3,n5});
        return min({n1,n3,n5});
    }
}
// 非递归动态规划求解
int func12(int n)
{
    int dp[n+1] = {0};
    dp[1] = dp[3] = dp[5] = 1;
    dp[2] = dp[4] = 2;
    for(int i=6;i<=n;i++)
    {
        dp[i] = min({dp[i-1],dp[i-3],dp[i-5]}) + 1;
    }
    return dp[n]; 
}
// 非递归动态规划求解
int func13(int n)
{
    int dp[n+1] = {0};
    int v[] = {1,3,5};
    int length = sizeof(v)/sizeof(v[0]);
    for(int i=1;i<=n;i++)
    {
        dp[i] = i;
        for(int j=0;j<length;j++)
        {
            if(i>=v[j] && (1+dp[i-v[j]])<dp[i])
            {
                dp[i] = 1+dp[i-v[j]];
            }
        }
    }
    return dp[n]; 
}
void test1()
{
    int n = 11;
    int dp[n+1] = {0};
    cout << func11(n,dp) << endl;
    cout << func12(n) << endl;
    cout << func13(n) << endl;
}

//-----------------------------------------------------------------------

//斐波那契数列 1 1 2 3 5 8
//求第n个斐波那契数列的值
int func21(int n,int dp[])
{
    if(dp[n]>0) //说明已经求过了 直接返回
    {
        return dp[n];
    }
    if(n==1 || n==2)
    {
        dp[n] = 1;
        return 1;
    }
    else
    {
        dp[n] = func21(n-1,dp)+func21(n-2,dp);
        return dp[n];
    }
    
}
int func22(int n)
{
    int dp[n+1] = {0};
    dp[1] = dp[2] = 1;
    for(int i=3;i<=n;i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
void test2()
{
    int n = 5;
    int dp[n+1] = {0};
    cout << func21(n,dp) << endl;
    cout << func22(n) << endl;
}

//-----------------------------------------------------------------------

//最大子段和
//问题：给定n个正数（可能为负）组成的序列a[1],a[2],...,a[n]，求该序列如：
//a[i]+a[i+1]+...+a[j]的子段和，当所给整数均为负数时，定义子段和为0；
//即：max{0,a[i]+a[i+1]+...+a[j]}
int func31()
{
    int arr[] = {-2,11,-4,13,-5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dp[n] = {0};
    dp[0] = arr[0]<0?0:arr[0];
    int maxV = dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i] = dp[i-1] + arr[i];
        if(dp[i]<0)
        {
            dp[i]=0;
        }
        if(dp[i]>maxV)
        {
            maxV=dp[i];
        }
    }
    return maxV;
}

void test3()
{
    cout << func31() << endl;
    bool dp[3];
    cout << endl;
}

//-----------------------------------------------------------------------

//LIS问题：求序列的最长非降子序列长度（可以不连续）
//5 3 4 1 8 7 9
int func41()
{
    int arr[] = {5,3,4,1,8,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dp[n] = {0};
    int maxV = 0;
    for(int i=0;i<n;i++)
    {
        dp[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<=arr[i] && (1+dp[j])>dp[i])
            {
                dp[i] = 1 + dp[j];
            }
        }
        if(dp[i]>maxV)
        {
            maxV=dp[i];
        }
    }
    return maxV;
}
void test4()
{
    cout << func41() << endl;
}
//-----------------------------------------------------------------------

//LCS问题：求两个序列的最长公共子序列的长度
//子串：字符必须连续
//子序列：字符可以不连续
string str1 = "helloworld";   //长度为n
string str2 = "hlweord";   //长度为m
int **dp = nullptr;
int **path = nullptr;
int func51(int n,int m)
{   
    if(n<0 || m<0)
    {
        return 0;
    }
    if(dp[n][m]>=0) //dp[n][m] n,m小于0时，指针也能指向某个值 因此判断是否小于0，小于0，直接返回
    {
        return dp[n][m];
    }
    if(str1[n]==str2[m])
    {
        dp[n][m] = func51(n-1,m-1)+1;
        path[n][m] = 1;
        return dp[n][m];
    }
    else
    {
        int len1 = func51(n-1,m);
        int len2 = func51(n,m-1);
        if(len1>=len2)
        {
            dp[n][m] = len1;
            path[n][m] = 2;
            return len1;
        }
        else
        {
            dp[n][m] = len2;
            path[n][m] = 3;
            return len2;
        }
    }
}

int func52(int i,int j)
{
    int flg = 0;
    for(int n=0;n<=i;n++)
    {
        for(int m=0;m<=j;m++)
        {
            if(n==0 || m==0)
            {
                dp[n][m] = 1;
                if(str1[n]==str2[m])
                {
                    flg = 1;
                    path[n][m] = 1;
                }
                else
                {
                    if(n==0 && m!=0)
                    {
                        path[n][m] = 3;
                    }
                    else if(n!=0 && m==0)
                    {
                        path[n][m] = 2;
                    }       
                }
                
                continue;
            }
            if(str1[n]==str2[m])
            {
                dp[n][m] = 1 + dp[n-1][m-1];
                path[n][m] = 1;
            }
            else
            {
                int len1 = dp[n-1][m];
                int len2 = dp[n][m-1];
                if(len1>=len2)
                {
                    dp[n][m] = len1;
                    path[n][m] = 2;
                }
                else
                {
                    dp[n][m] = len2;
                    path[n][m] = 3;
                }
            }
        }
    }
    if(flg==0) return 0;
    return dp[i][j];
}

void backtrace(int n,int m)
{
    if(n<0 || m<0)
    {
        return;
    }
    if(path[n][m]==1)
    {
        backtrace(n-1,m-1);
        cout << str1[n] << " ";
    }
    else
    {
        if(path[n][m]==2)
        {
            backtrace(n-1,m);
        }
        else
        {
            backtrace(n,m-1);
        }
    }
}

void test51()
{
    int n = str1.size();
    int m = str2.size();
    dp = new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[m];
        for(int j=0;j<m;j++)
        {
            dp[i][j] = -1;
        }
    }
    path = new int*[n];
    for(int i=0;i<n;i++)
    {
        path[i] = new int[m];
        for(int j=0;j<m;j++)
        {
            path[i][j] = -1;
        }
    }
    cout << func51(n-1,m-1) << endl;
    backtrace(n-1,m-1);
    cout << endl;
}

void test52()
{
    int n = str1.size();
    int m = str2.size();
    dp = new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[m];
        for(int j=0;j<m;j++)
        {
            dp[i][j] = -1;
        }
    }
    path = new int*[n];
    for(int i=0;i<n;i++)
    {
        path[i] = new int[m]();
    }
    cout << func52(n-1,m-1) << endl;
    backtrace(n-1,m-1);
    cout << endl;
}

//------------------------------------------

//问题：三角数组求和
//给定一个三角形，找出自定向下得最小路径和，每一步只能移动到下一行中相邻得节点上
int func61()
{
    vector<int> v1 = {2};
    vector<int> v2 = {3,4};
    vector<int> v3 = {6,5,7};
    vector<int> v4 = {4,1,8,3};
    vector<int> v5 = {4,1,8,3,7};
    vector<vector<int>> vv = {v1,v2,v3,v4,v5};
    int **dp = nullptr; //dp[i][j]  以第i行第j列元素开始 选择数字和的最小值
    int n = vv.size();
    dp = new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[vv[vv.size()-1].size()];
    }
    for(int i=0;i<vv[vv.size()-1].size();i++)
    {
        dp[n-1][i] = vv[vv.size()-1][i];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<vv[i].size();j++)
        {
            dp[i][j] = vv[i][j] + min({dp[i+1][j],dp[i+1][j+1]});   //当前节点 + min{下一层当前列，下一层下一列}
        }
    }
    return dp[0][0];
}

void test6()
{
    cout << "test6: " << func61() << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test51();
    test52();
    test6();
    system("pause");
    return 0;
}