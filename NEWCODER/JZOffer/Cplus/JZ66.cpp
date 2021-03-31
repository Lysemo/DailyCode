/**
 * 题目：
 * 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
 * 但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），
 * 因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 * 
 * 示例：
 * 输入：
 * 5,10,10
 * 输出：
 * 21
 * 
 */ 
#include<vector>
#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

//深度优先 使用递归或栈
//广度优先 使用队列
//DFS
class Solution1
{
public:
    using V = vector<int>;
    using VV = vector<V>;
    int dir[5] = {-1,0,1,0,-1};
    
    int check(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
    
    void dfs(int x,int y,int threshold,int r,int c,int &res,VV &mark)
    {
        if(x<0 || x>=r || y<0 || y>=c || mark[x][y]==1)
        {
            return;
        }
        if(check(x)+check(y)>threshold)
        {
            return;
        }
        mark[x][y] = 1;
        res += 1;
        for(int i=0;i<4;i++)
        {
            dfs(x+dir[i],y+dir[i+1],threshold,r,c,res,mark);    //朝左下右上尝试走
            //递归，深度优先
        }
    }
    
    int movingCount(int threshold, int rows, int cols) 
    {
        if(threshold<=0)
        {
            return 0;
        }
        VV mark(rows,V(cols,-1));
        int res = 0;
        dfs(0,0,threshold,rows,cols,res,mark);
        return res;
    }
};

//BFS
class Solution2 
{
public:
    using pii = pair<int,int>;
    int dir[5] = {-1, 0, 1, 0, -1};
    int check(int n) {
        int sum = 0;
 
        while (n) {
            sum += (n % 10);
            n /= 10;
        }
 
        return sum;
    }
    int movingCount(int sho, int rows, int cols)
    {
        if (sho <= 0) {
            return 0;
        }
 
        int ret = 0;
        int mark[rows][cols];
        memset(mark, -1, sizeof(mark));
        queue<pii> q;
        q.push({0, 0});
        mark[0][0] = 1;
 
 
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            // 每次保证进队列的都是满足条件的坐标
            ++ret;
 
            for (int i = 0; i < 4; ++i) {
                int x = node.first + dir[i];
                int y = node.second + dir[i + 1];
 
                if (x >= 0 && x < rows && y >= 0 && y < cols && mark[x][y] == -1) {
                    if (check(x) + check(y) <= sho) {   //如果条件都满足 入队列
                        q.push({x, y});
                        mark[x][y] = 1;
                    }
                }
            }
        }
 
        return ret;
    }
};

int main()
{
    Solution1 s1;
    cout << s1.movingCount(5,10,10) << endl;
    system("pause");
    return 0;
}