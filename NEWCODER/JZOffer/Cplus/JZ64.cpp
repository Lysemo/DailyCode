/**
 * 题目：
 *  给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
 * 他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
 * {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
 * {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 * 窗口大于数组长度的时候，返回空
 * 
 * 示例：
 * 输入：
 * [2,3,4,2,6,2,5,1],3
 * 输出：
 * [4,4,6,6,6,5]
 */ 
#include<iostream>
#include<vector>
#include<deque>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size) 
{
    if(size>num.size() || size==0) return {};
    vector<int> res;
    int n = num.size()-size+1;
    for(int i=0;i<n;i++)
    {
        int maxV = -1;
        for(int j=0;j<size;j++)
        {
            maxV = maxV>num[i+j]?maxV:num[i+j];
        }
        res.push_back(maxV);
    }
    return res;
}

vector<int> maxInWindows_(const vector<int>& num, unsigned int size) 
{
    vector<int> res;
    deque<int> s;
    //双端队列，队头存储最大元素的索引
    for(unsigned int i = 0; i<num.size();i++)
    {
        //当s里面有元素，将当前元素插入到第一个大于它的数字后面，小于它的数字全部弹出；因为它们不会成为窗口最大的值
        while(s.size() && num[i]>=num[s.back()])    
        {
            s.pop_back();
        }
        while(s.size() && i - s.front() + 1>size)   //  当s里面有元素，队头元素已经不在窗口内，弹出队头元素
        {
            s.pop_front();
        }
        s.push_back(i); //当前元素入到队尾
        if(size && i+1>=size)   //如果窗口大小>0 且 满足最小窗时，添加队头元素到数组
        {
            res.push_back(num[s.front()]);
        }
    }
    return res;
}

int main()
{
    vector<int> res = maxInWindows({2,3,4,2,6,2,5,1},3);
    vector<int> res_ = maxInWindows_({2,3,4,2,6,2,5,1},3);
    return 0;
}