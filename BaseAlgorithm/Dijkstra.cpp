#include<iostream>
#include<vector>

using namespace std;
//Dijkstra(迪杰斯特拉)单源最短路径问题，求出起始节点到其他每个节点的最短路径；
vector<int> Dijkstra(vector<vector<int>> &graph,int start)
{
    int n = graph.size();
    vector<int> visited(n,0);
    vector<int> mdist(n,-1);
    //记录初始最短距离
    for(int i=0;i<n;++i)
    {
        mdist[i] = graph[start][i];
    }
    visited[start] = 1; //标记起始节点
    //对n个节点求最短的路径
    for(int i=0;i<n;++i)
    {
        int mv = INT_MAX;
        int mi = -1;
        //找中间节点
        for(int j=0;j<n;++j)
        {
            if(visited[j]==0 && mdist[j]<mv)
            {
                mv = mdist[j];
                mi = j;
            }
        }
        //更新其他节点最短距离
        for(int k=0;k<n;k++)
        {
            //如果（起点到中间节点的最短距离+中间节点到其他节点的距离）< 起点到其他节点的最短距离
            //更新
            if(visited[k]==0 && mdist[k]>(mdist[mi]+graph[mi][k]))  
            {
                mdist[k] = mdist[mi]+graph[mi][k];
            }
        }
        visited[i] = 1;
    }
    return mdist;
}

int main()
{
    vector<vector<int>> graph;
    for(int i=0;i<4;i++)
    {
        vector<int> tmp;
        for(int j=0;j<4;j++)
        {
            tmp.push_back(INT_MAX);
        }
        graph.push_back(tmp);
    }
    graph[0][0] = 0;
    graph[0][1] = 600;
    graph[0][2] = 800;

    graph[1][0] = 600;
    graph[1][1] = 0;
    graph[1][2] = 100;
    graph[1][3] = 200;

    graph[2][0] = 800;
    graph[2][1] = 100;
    graph[2][2] = 0;
    graph[2][3] = 300;

    graph[3][1] = 200;
    graph[3][2] = 300;
    graph[3][3] = 0;

    vector<int> res = Dijkstra(graph,0);

    return 0;
}