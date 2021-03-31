/**
 * 题目：
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 * 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
 * 
 */ 
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<double> vec;
void Insert(int num) 
{
    vec.push_back(num);
}

double GetMedian() 
{ 
    sort(vec.begin(), vec.end());
    int sz = vec.size();
    if((sz%2)==0)
    {
        return (vec[sz/2-1]+vec[sz/2])/2;
    }
    else{
        return vec[sz/2];
    }
}

void Insert_(int num) 
{
    if(vec.empty())
    {
        vec.push_back(num);
    }
    else
    {
        //lower_bound() : 返回第一个>=num的数的迭代器
        auto it = lower_bound(vec.begin(), vec.end(), num);
        vec.insert(it, num);
    }
}

double GetMedian_() 
{ 
    int sz = vec.size();
    if((sz%2)==0)
    {
        return (vec[sz/2-1]+vec[sz/2])/2;
    }
    else{
        return vec[sz/2];
    }
}

priority_queue<int> maxHeap;
priority_queue<int,vector<int>,greater<int>> minHeap;
int count1 = 0;
void Insert__(int num) 
{
    if(count1%2==0)
    {
        maxHeap.push(num);
        int max = maxHeap.top();
        maxHeap.pop();
        minHeap.push(max);
    }
    else
    {
        minHeap.push(num);
        int min = minHeap.top();
        minHeap.pop();
        maxHeap.push(min);
    }
    count1++;
}

double GetMedian__() 
{ 
    if(count1%2 ==0)
    {
        return static_cast<double>(minHeap.top()+maxHeap.top())/2;
    }
    else
    {
        return static_cast<double>(minHeap.top());
    }
}

int main()
{
    Insert(2);
    Insert(3);
    Insert(1);
    Insert(10);
    cout << GetMedian() << endl;
    Insert_(2);
    Insert_(3);
    Insert_(1);
    Insert_(10);
    cout << GetMedian_() << endl;
    Insert__(2);
    Insert__(3);
    Insert__(1);
    Insert__(10);
    cout << GetMedian__() << endl;
    system("pause");
    return 0;
}