/**
 * 题目描述：
 * 给定一个 n 行 m 列的地牢，其中 '.' 表示可以通行的位置，'X' 表示不可通行的障碍，
 * 牛牛从 (x0 , y0 ) 位置出发，遍历这个地牢，和一般的游戏所不同的是，他每一步只能按照一些指定的步长遍历地牢，
 * 要求每一步都不可以超过地牢的边界，也不能到达障碍上。地牢的出口可能在任意某个可以通行的位置上。
 * 牛牛想知道最坏情况下，他需要多少步才可以离开这个地牢。
 * 
 * 输入描述：
 * 每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 50），表示地牢的长和宽。
 * 接下来的 n 行，每行 m 个字符，描述地牢，地牢将至少包含两个 '.'。接下来的一行，包含两个整数 x0, y0，
 * 表示牛牛的出发位置（0 <= x0 < n, 0 <= y0 < m，左上角的坐标为 （0, 0），出发位置一定是 '.'）。
 * 之后的一行包含一个整数 k（0 < k <= 50）表示牛牛合法的步长数，接下来的 k 行，
 * 每行两个整数 dx, dy 表示每次可选择移动的行和列步长（-50 <= dx, dy <= 50）
 * 
 * 输出描述：
 * 输出一行一个数字表示最坏情况下需要多少次移动可以离开地牢，如果永远无法离开，输出 -1。以下测试用例中，
 * 牛牛可以上下左右移动，在所有可通行的位置.上，地牢出口如果被设置在右下角，牛牛想离开需要移动的次数最多，为3次。
 * 
 * 示例：
 * 输入：
 * 3 3
 * ...
 * ...
 * ...
 * 0 1
 * 4
 * 1 0
 * 0 1
 * -1 0
 * 0 -1
 * 输出：
 * 3
 */ 
#include<iostream>
#include<queue>

using namespace std;

/**
 * 解题思路：
 * 该题题意为 起点到每个可能出口的最小距离di,求这些距离中最大的一个
 * 1.对除起点外的每个可能的出口进行遍历
 * 2.对于一个出口，利用广度优先求起点到该出口的最短距离（矩阵/图）
 * 3.求所有最短距离的最大值
 */ 

//利用广度优先求起点与出口间的最短距离
int bfs(int ex,int ey,int x0,int y0,int n,int m,int k,char **grid,int **dirs)
{
    bool **marked = new bool*[n];   //标记该节点走过没
    for(int i=0;i<n;i++)    //初始全没走过
    {
        marked[i] = new bool[m];
        for(int j=0;j<m;j++)
        {
            marked[i][j] = false;
        }
    }
    queue<pair<int,int>> que;
    que.push({x0,y0});  //加入起点
    marked[x0][y0] = true;  //起点走过
    int steps = 0;   //记录最小步数
    while (!que.empty())
    {
        int sz = que.size();
        steps ++;   //步数加1  广度优先的第几层
        while (sz--)
        {
            pair<int,int> p = que.front();  //弹出队头
            que.pop();
            int x = p.first;    //当前位置
            int y = p.second;
            marked[x][y] = true;    //当前位置走过
            for(int i=0;i<k;i++)    //遍历k个方向 分支可能一步到达的地方
            {
                int nx = x + dirs[i][0];    //新的位置
                int ny = y + dirs[i][1];
                if(nx==ex&&ny==ey&&grid[nx][ny]=='.')   //如果新的位置为出口位置 返回最短距离
                {
                    return steps;
                }
                if(nx>=n||nx<0||ny>=m||ny<0||grid[nx][ny]=='X'||marked[nx][ny]) //如果新位置不可走，剪枝，没有下一步（已经走过的不能再走）
                {
                    continue;
                }
                que.push({nx,ny});  //将新的位置加入队列
            }
        }
        
    }
    return -1;  //如果遍历完所有位置 都没有走出去，则无法到达，返回-1
    
}


int main()
{
    int n,m;
    while (cin>>n>>m)
    {
        char **grid = new char*[n];
        for(int i=0;i<n;i++)
        {
            grid[i] = new char[m];
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }
        int x0,y0;
        queue<pair<int,int>> que;
        cin>>x0>>y0;
        int k;
        cin>>k;
        int **dirs = new int*[k];
        for(int i=0;i<k;i++)
        {
            dirs[i] = new int[2];
            cin>>dirs[i][0]>>dirs[i][1];
        }
        int res = -1;   //最大距离为-1
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==x0 && j==y0)
                {
                    continue;   //起点不能作为出口
                }
                if(grid[i][j]=='.') //如果可以作为出口
                {
                    int steps = bfs(i,j,x0,y0,n,m,k,grid,dirs); //计算最短距离
                    if(steps==-1)   //如果有一个为-1，即不可到达；则返回-1，因为是求最大的距离
                    {
                        cout << steps << endl;
                        return 0;
                    }
                    res = max(res,steps);   //更新最大距离
                }
            }
        }
        cout << res << endl;

    }
    system("pause");
    return 0;
}