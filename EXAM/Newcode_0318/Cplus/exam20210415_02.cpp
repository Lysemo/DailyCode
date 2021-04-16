#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct Person
{   
    int id;
    int attack;
    int money;
    bool operator<(const Person &p) //按攻击力从小到大排
    {
        return attack<p.attack;
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>> mms;   //用于存储k个最大金额
    int i = n;
    int *attacks = new int[n];
    int *moneys = new int[n];
    int *maxM = new int[n]();
    vector<int> tmp;
    while (i)   //数据录入
    {
        cin>>attacks[n-i];
        i--;
    }
    i = n;
    while (i)
    {
        cin>>moneys[n-i];
        i--;
    }
    //特殊情况处理
    if(k==0)    //如果没有子弹，每个人最大收益为本身
    {
        for(int i=0;i<n-1;i++)
        {
            cout << moneys[i] << " ";
        }
        cout << moneys[n-1];
        return 0;
    }
    if(n==1)    //如果只要一个人，最大收益为本身
    {
        cout<<moneys[0];
        return 0;
    }
    Person *pss = new Person[n]();
    for(int i=0;i<n;i++)
    {
        pss[i].id = i;
        pss[i].attack = attacks[i];
        pss[i].money = moneys[i];
    }
    sort(pss,pss+n);    //按攻击力从小到大排序
    maxM[pss[0].id] = pss[0].money; //排序后第一个人攻击力最小，最大收益为本身
    mms.push(pss[0].money); //将收益放入优先级队列
    for(int i=1;i<n;i++)    //对1-n人
    {
        int sz = mms.size();
        maxM[pss[i].id] = pss[i].money; //最大收益等于本身+（k个最大收益和，前面的人不足或等于k时，收益全部获取）
        while (sz--)
        {
            maxM[pss[i].id] += mms.top();   //每一个都加进来
            tmp.push_back(mms.top());   //将弹出的先保存下 的重新加入
            mms.pop();
        }
        sz = tmp.size();
        while (sz--)
        {
            mms.push(tmp.front());  //重新加入
            tmp.pop_back();
        }
        mms.push(pss[i].money); //加入新的收益
        if(mms.size()>k)    //如果可击杀人的个数大于k，则弹出一个最小的，使其个数为k（只可能时k+1）
        {
            mms.pop();
        }  
    }
    for(int j=0;j<n-1;j++)
    {
        cout << maxM[j] << " "; //打印每个人的最大收益
    }
    cout << maxM[n-1];  //为避免最后一个字符没有 空格，单独打印
    return 0;
}