/**
 * 题目描述：
 * 小易总是感觉饥饿，所以作为章鱼的小易经常出去寻找贝壳吃。最开始小易在一个初始位置x_0。
 * 对于小易所处的当前位置x，他只能通过神秘的力量移动到 4 * x + 3或者8 * x + 7。
 * 因为使用神秘力量要耗费太多体力，所以它只能使用神秘力量最多100,000次。
 * 贝壳总生长在能被1,000,000,007整除的位置(比如：位置0，位置1,000,000,007，位置2,000,000,014等)。
 * 小易需要你帮忙计算最少需要使用多少次神秘力量就能吃到贝壳。
 * 
 * 输入描述：
 * 输入一个初始位置x_0,范围在1到1,000,000,006
 * 
 * 输出描述：
 * 输出小易最少需要使用神秘力量的次数，如果使用次数使用完还没找到贝壳，则输出-1
 * 
 * 示例：
 * 输入：
 * 125000000
 * 输出：
 * 1
 */ 

#include<iostream>
#include<queue>
#include<unordered_set>

using namespace std;

/**
 * 解题思路：
 * 发现两个式子的数学规律：
 * 8x+7 -> 3个 2x+1
 * 4x+3 -> 2个 2x+1
 * 
 * 每次跑1个2x+1，看哪次对1000000007取余为0，将次数分解为2和3次数的最小值；
 * 最多允许300,000次
 * 
 * 如果用bsf广度搜索，每次搜2步，要2^100,000次，最多执行；
 */ 

int main()
{
    int x0;
    while (cin>>x0)
    {
        //8x+7为3个2x+1
        //4x+3为2个2x+1
        int num = 0;
        while (x0!=0 && num<= 300000)   //300000为最远可以跑到的地方
        {
            x0 = ((x0<<1)+1)%1000000007;    //看最终x0=0时，是2x+1的几倍
            num++;
        }
        int res = (num+2)/3;    //将 倍数 分解为min(2的个数+3的个数)
        cout << ((res>100000)?-1:res) << endl;  //如果个数大于100000，返回-1
    }
    return 0;
}

// int main()
// {
//     long long pos;
//     while (cin>>pos)
//     {
//         queue<long long> que;
//         unordered_set<long long> st;
//         int num = 0;
//         long long x1;
//         long long x2;
//         st.insert(pos);
//         que.push(pos);
//         while (!que.empty())
//         {
//             int sz = que.size();
//             num++;
//             while (sz--)
//             {
//                 x1 = que.front()*4+3;
//                 x2 = que.front()*8+7;
//                 que.pop();
//                 if((x1%1000000007)==0 || (x2%1000000007)==0)
//                 {
//                     cout << num << endl;
//                     return 0;
//                 }
//                 if(st.find(x1%1000000007)==st.end())
//                 {
//                     que.push(x1%1000000007);
//                     st.insert(x1%1000000007);
//                 }
//                 if(st.find(x2%1000000007)==st.end())
//                 {
//                     que.push(x2%1000000007);
//                     st.insert(x2%1000000007);
//                 }
//             }
//             if(num==100000)
//             {
//                 cout << -1 << endl;
//                 return 0;
//             } 
//         }
//         cout << -1 << endl;
//         return 0;
//     }
//     return 0;
// }

// int main()
// {
//     int pos;
//     while (cin>>pos)
//     {
//         int num = 0;
//         long long x0 = pos;
//         for(;num<100000;num++)
//         {
//             x0 = (8*x0+7)%1000000007;
//             if(x0==0)
//             {
//                 cout << num+1 << endl;
//                 return 0;
//             }
//         }
//         num = 1;
//         x0 = pos;
//         x0 = (4*x0+3)%1000000007;
//         for(;num<100000;num++)
//         {
//             x0 = (8*x0+7)%1000000007;
//             if(x0==0)
//             {
//                 cout << num+1 << endl;
//                 return 0;
//             }
//         }
//         num = 2;
//         x0 = pos;
//         x0 = (4*x0+3)%1000000007;
//         x0 = (4*x0+3)%1000000007;
//         for(;num<100000;num++)
//         {
//             x0 = (8*x0+7)%1000000007;
//             if(x0==0)
//             {
//                 cout << num+1 << endl;
//                 return 0;
//             }
//         }
//         cout << -1 << endl;
//     }
//     return 0;
// }