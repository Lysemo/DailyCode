#include<iostream>
#include<algorithm>

using namespace std;

class Solution1
{
    //硬币问题
    //1，3，5分硬币，组成面额11所需的最少硬币数量

    //每次先装最大的  如果最大的 小于 剩余面额；再装次大的，依次类推；
    //直到剩余面额为0时，退出循环
public:
    int func()
    {
        int v[] = {1,3,5};
        int minN = 0;
        int c = 11;
        int sz = sizeof(v)/sizeof(v[0]);
        sort(v,v+sz,[](int a,int b)->bool{return a>b;});
        int i = 0;
        while (c>0)
        {
            if(c>=v[i])
            {
                minN++;
                c -= v[i];
            }
            else
            {
                i++;
            }
        }
        return minN;
    }

    void test()
    {
        cout << func() << endl;
    }
    
};


class Solution2
{
    //部分背包问题
    //n个物品，第i个物品重量为wi，价值为vi
    //在总容量不超过c的情况下，装入物品，使总价值尽可能高
    //每种物品可取一部分，价值和重量按比例计算

    //每次取性价比最高的物品
public:
    struct CGood
    {
        int id;
        int w;
        int v;

        double getPrice()
        {
            return (v*1.0)/w;
        }

        bool operator>(const CGood &g)
        {
            return getPrice()>(g.v*1.0)/g.w;
        }

    };

    double func()
    {
        int w[] = {8,6,4,2,5};
        int v[] = {6,4,7,8,6};
        int c = 12;
        double maxP = 0.0;
        const int sz = sizeof(w)/sizeof(w[0]);
        int sel[sz] = {0};
        CGood goods[sz];
        for(int i=0;i<sz;i++)
        {
            goods[i].id = i;
            goods[i].w = w[i];
            goods[i].v = v[i];
        }
        sort(goods,goods+sz,[](CGood a,CGood b)->bool{return a>b;});

        for(int i=0;i<sz;i++)
        {
            if(c>=w[i])
            {
                maxP += goods[i].v;
                c -= goods[i].w;
                sel[i] = 1;
            }
            else
            {
                maxP += (goods[i].v*1.0*c/goods[i].w);
                sel[i] = 2;
                break;
            }
        }

        for(int i=0;i<sz;i++)
        {
            cout << i << ":" << sel[i] << "    ";
        }
        cout << endl;

        return maxP;

    }

    void test()
    {
        cout << func() << endl;
    }

};


class Solution3
{
    //m个柜台服务n个顾客的问题
    //m个柜台提供服务，每个柜台给一个用户提供服务的时间是t（用数组表示每一个柜台提供服务的时间）
    //问怎么安排，使柜台给所有用户提供服务的时间最少？

    //先给效率快的柜台安排
    //如果新一个顾客安排后 效率快的柜台 的总服务时间 大于 安排给 其他柜台的 总服务时间，则安排给其他柜台
public:
    struct Constomer
    {
        int id;
        int time;

        bool operator<(const Constomer c)
        {
            return time < c.time;
        }
    };
    
    
    int func()
    {
        int arr[] = {3,2,4};
        const int sz = sizeof(arr)/sizeof(arr[0]);
        Constomer cons[sz];
        for(int i=0;i<sz;i++)
        {
            cons[i].id = i;
            cons[i].time = arr[i];
        }
        sort(cons,cons+sz);
        int n = 15;
        int mintime = 0;
        int num[sz] = {0};
        for(int i=0;i<n;i++)    //15个用户
        {   
            int time = cons[0].time*(num[0]+1);
            int j = 1;
            for(;j<sz;j++)  //其他sz-1个客服
            {
                int t = cons[j].time*(num[j]+1);
                if(t<time)  //假如把客户给其他客服的时间短 则给哪个客服
                {
                    mintime = t;    //服务的最短时间，取决于最长的一个
                    num[j]++;
                    break;  //因为时间本身就是从 小到大排   有一个客服时间比较短时，直接给，不用判断后面的客服
                }
            }
            if(j==sz)
            {
                mintime = time;
                num[0]++;
            }
        }
        for(int i=0;i<sz;i++)
        {
            cout << "id:" << cons[i].id << "    time:" << cons[i].time << "     num:" << num[i] << endl; 
        }

        return mintime;
    }
    void test()
    {
        cout << func() << endl;
    }
};




int main()
{
    Solution1 s1;
    s1.test();

    Solution2 s2;
    s2.test();

    Solution3 s3;
    s3.test();

    system("pause");
    return 0;
}