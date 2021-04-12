#include<iostream>
#include<vector>

using namespace std;
/*
问题描述：
网格中，找出从左上角网格到右下角网格 最小距离
对于任意一个网格，它下步只能朝右走 或 朝下走

动态规划问题：
1.确定状态转移方程
2.确定初始状态（特殊情况的值）
*/
int minPathSum(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> dp(r,vector<int>(c,0));
    dp[0][0] = grid[0][0];
    for(int i=1;i<c;i++)    //行路径
    {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    for(int i=1;i<r;i++)    //列路径
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j]; //其他位置最短距离 只能从上面或左边过来
        }
    }
    return dp[r-1][c-1];
}

int main()
{
    vector<vector<int>> grid;
    grid.push_back({1,3,1});
    grid.push_back({1,5,1});
    grid.push_back({4,2,1});
    cout << minPathSum(grid) << endl;
    system("pause");
    return 0;
}