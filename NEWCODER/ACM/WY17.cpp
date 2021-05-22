/**
 * 题目描述：
 * 有一片1000*1000的草地，小易初始站在(1,1)(最左上角的位置)。小易在每一秒会横向或者纵向移动到相邻的草地上吃草
 * (小易不会走出边界)。大反派超超想去捕捉可爱的小易，他手里有n个陷阱。第i个陷阱被安置在横坐标为xi ，
 * 纵坐标为yi 的位置上，小易一旦走入一个陷阱，将会被超超捕捉。你为了去解救小易，需要知道小易最少
 * 多少秒可能会走入一个陷阱，从而提前解救小易。
 * 
 * 输入描述：
 * 第一行为一个整数n(n ≤ 1000)，表示超超一共拥有n个陷阱。
 * 第二行有n个整数xi，表示第i个陷阱的横坐标
 * 第三行有n个整数yi，表示第i个陷阱的纵坐标
 * 保证坐标都在草地范围内。
 * 
 * 输出描述：
 * 输出一个整数,表示小易最少可能多少秒就落入超超的陷阱
 * 
 * 示例：
 * 输入：
 * 3
 * 4 6 8
 * 1 2 1
 * 输出：
 * 3
 */ 
#include<iostream>
#include<algorithm>

using namespace std;

// int main()
// {
//     // 求 初始位置（1，1）到各个陷阱位置的城市街区距离
//     // 找出最小的 即可
//     int n;
//     while (cin>>n)
//     {
//         int *xs = new int[n];
//         int *ys = new int[n];
//         for(int i=0;i<n;i++)
//         {
//             cin>>xs[i];
//         }
//         for(int i=0;i<n;i++)
//         {
//             cin>>ys[i];
//         }
//         int mindis = 2001;
//         for(int i=0;i<n;i++)
//         {
//             int dis = (xs[i]-1)+(ys[i]-1);
//             if(dis<mindis)
//             {
//                 mindis = dis;
//             }
//         }
//         cout << mindis << endl;
//     }
    
//     return 0;
// }

int main()
{
    // 求 初始位置（1，1）到各个陷阱位置的城市街区距离
    // 排序
    // 第一个即为最小距离
    int n;
    while (cin>>n)
    {
        int *xs = new int[n];
        int tmp;
        for(int i=0;i<n;i++)
        {
            cin>>xs[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            xs[i] += tmp;
        }
        sort(xs,xs+n);
        cout << xs[0]-2 << endl;
    }
    return 0;
}