#include<iostream>
#include<vector>
#include<string>

using namespace std;
//N皇后问题
//在（x,y）位置放置皇后，攻击位置确定
void put_queen(int x,int y,vector<vector<int>> &attack)
{
    const int xi[] = {-1,1,0,0,-1,-1,1,1};
    const int yi[] = {0,0,-1,1,-1,1,-1,1};
    attack[x][y] = 1;
    for(int i=1;i<attack.size();i++)    //进行n-1个攻击候选区确定
    {
        for(int j=0;j<8;j++)    //8个方向
        {
            int ax = x + i*xi[j];
            int ay = y + i*yi[j];
            if(ax>=0 && ax<attack.size() && ay>=0 && ay<attack.size())  //必须在范围内
            {
                attack[ax][ay] = 1;
            }
        }
    }
}

//回溯
void back_trace(int k,int n,vector<vector<int>> &attack,vector<string> &queen,vector<vector<string>> &res)
{
    if(k==n)    //如果n步走完后  到这 说明放置合理  保存解
    {
        res.push_back(queen);
        return;
    }
    for(int i=0;i<queen.size();i++) //对第k行 每一列进行放置尝试
    {
        if(attack[k][i]==0) //判断当前位置是否可以放皇后
        {
            vector<vector<int>> tmp = attack;   //备份攻击数组
            queen[k][i] = 'Q';  //能放
            put_queen(k,i,attack);  //确定攻击区域
            back_trace(k+1,n,attack,queen,res); //进行下一行皇后确定
            attack = tmp;   //恢复back_trace前的状态
            queen[k][i] = '.';  //恢复更改前的值
        }
    }
}

int main()
{
    vector<vector<string>> res;
    vector<string> queen;
    vector<vector<int>> attack;
    for(int i=0;i<4;i++)
    {
        vector<int> tmp;
        for(int j=0;j<4;j++)
        {
            tmp.push_back(0);
        }
        queen.push_back("....");
        attack.push_back(tmp);
    }
    back_trace(0,4,attack,queen,res);
    return 0;
}