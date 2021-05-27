/*
[题目描述]
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，
小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 
小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板

[输入描述]
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)

[输出描述]
输出小易最少需要跳跃的步数,如果不能到达输出-1

[示例]
输入：
4 24
输出：
5
*/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

int main()
{
    int N,M;
    while (cin>>N>>M)
    {
        vector<int> dp(M+1,INT_MAX);
        dp[N] = 0;
        for(int i=N;i<=M;i++)
        {
            //如果某个点不可到达（无穷大时），说明从该点也到不了M点，故跳过；
            if(dp[i]==INT_MAX)
            {
                continue;
            }
            //求约数
            for(int j=2;(j*j)<=i;j++)   //以sqrt(i)作为分界线，当i%j==0或i%k==0时，(j*k)=(k*j),其中j<sqrt(i),k>sqrt(i),找到j，k也就找到了
            {
                if(i%j==0)
                {
                    if(i+j<=M)
                    {
                        dp[i+j] = min(dp[i]+1,dp[i+j]); //取dp[i]+1和dp[i+j]的最小值    dp[i]存储从N点到i点的最少步数
                    }
                    if(i+(i/j)<=M)
                    {
                        dp[i+(i/j)] = min(dp[i]+1,dp[i+(i/j)]);
                    }
                }
            }
        }
        if(dp[M]==INT_MAX)
        {
            dp[M] = -1;
        }
        cout << dp[M] << endl;
    }
    return 0;
}

/*
//复杂度过高

void getYue(int n,vector<int> &res)
{
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            res.push_back(i);
        }
    }
}

int main()
{
    int N,M;
    queue<int> pq;
    while(cin>>N>>M)
    {
        int num = 0;
        unordered_set<int> st;
        st.insert(N);
        pq.push(N);
        while (!pq.empty())
        {
            int sz = pq.size();
            num++;
            while (sz--)
            {
                int tmp = pq.front();
                pq.pop();
                vector<int> res;
                getYue(tmp,res);
                for(int i=0;i<res.size();i++)
                {
                    if(tmp+res[i]==M)
                    {
                        cout << num << endl;
                        return 0;
                    }
                    else if(tmp+res[i]<M && st.find(tmp+res[i])==st.end())
                    {
                        pq.push(tmp+res[i]);
                        st.insert(tmp+res[i]);
                    }
                }
            }
            
        }
        cout << -1 << endl;
    }
    return 0;
}
*/

/*
//贪婪算法并不一定能得到最优解，但是一个可行的，较好的解。

void getYue(int n,vector<int> &res)
{
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            res.push_back(i);
        }
    }
}

int num = 0;

bool func(int N,int M)
{
    if(N==M)
    {
        return true;
    }
    else if(N<M)
    {
        vector<int> res;
        getYue(N,res);
        for(int i=res.size()-1;i>=0;i--)
        {
            num++;
            int tmp = N + res[i];
            if(tmp<=M)
            {
                if(func(tmp,M))
                {
                    return true;
                }
            }
            num--;
        }
    }
    return false;
}
int main()
{
    int N,M;
    while (cin>>N>>M)
    {
        if(func(N,M))
        {
            cout << num << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        
        
    }    
    return 0;
}
*/