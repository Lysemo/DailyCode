/*
[题目描述]
小明同学把1到n这n个数字按照一定的顺序放入了一个队列Q中。现在他对队列Q执行了如下程序：
while(!Q.empty())              //队列不空，执行循环
{
    int x=Q.front();            //取出当前队头的值x
    Q.pop();                 //弹出当前队头
    Q.push(x);               //把x放入队尾
    x = Q.front();              //取出这时候队头的值
    printf("%d\n",x);          //输出x
    Q.pop();                 //弹出这时候的队头
}
做取出队头的值操作的时候，并不弹出当前队头。
小明同学发现，这段程序恰好按顺序输出了1,2,3,...,n。现在小明想让你构造出原始的队列，你能做到吗？

[输入描述]
第一行一个整数T（T ≤ 100）表示数据组数，每组数据输入一个数n（1 ≤ n ≤ 100000），输入的所有n之和不超过200000。

[输出描述]
对于每组数据，输出一行，表示原始的队列。数字之间用一个空格隔开，不要在行末输出多余的空格.

[示例]
输入:
4
1
2
3
10
输出:
1
2 1
2 1 3
8 1 6 2 10 3 7 4 9 5
*/

#include<iostream>
#include<deque>

using namespace std;

/*
解题思想：
利用双端队列，对上述操作进行逆操作

将队头元素放到队尾，再输出新的队头
逆操作为：
先向队头插入元素，然后将队尾元素放到队头
*/

int main()
{
    int n;
    while (cin>>n)
    {
        int *arr = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
            deque<int> dq;
            for(int j=arr[i];j>=1;j--)  //逆向操作时，初始队列中没有元素，从最大的->最小的 元素依次入队列
            {
                dq.push_front(j);
                int x = dq.back();
                dq.pop_back();
                dq.push_front(x);
            }
            while (dq.size()!=1)
            {
                cout << dq.front() << " ";
                dq.pop_front();
            }
            cout << dq.front() << endl;
            dq.pop_front();
        }
    }
    return 0;
}