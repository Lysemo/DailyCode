/**
 * 
 * 题目：
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
 * 如果有多对数字的和等于S，输出两个数的乘积最小的。
 * 输出描述：对应每个测试案例，输出两个数，小的先输出。
 * 
 * 示例：
 * 输入：
 * [1,2,4,7,11,15],15
 * 输出：
 * [4,11]
 * 
 */ 

#include<iostream>
#include<vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    vector<int> res;
    //查找2个数和为sum的索引
    //左右两个边界
    for(int j = array.size()-1;j>0;j--)
    {
        //移动左边界，查找值
        for(int i = 0;i<j;i++)
        {
            //左边界与右边界和 大于sum时 ，直接跳出
            if((array[i]+array[j])>sum) break;
            // = sum，存储索引，并退出
            if((array[i]+array[j])==sum) 
            {
                res.push_back(i);
                res.push_back(j);
                break;
            }
            //否则，和小于sum，此时使左边界++
        }
    }
    //没找到 返回空数组
    if(res.size()==0) return {};
    //只有一个  直接返回
    if(res.size()==2) return {array[res[0]],array[res[1]]};
    int mini = 0;
    int minv = res[0]*res[1];
    //有多个，先比较乘积最小的 然后返回
    for(int i=2;i<res.size()-1;i=i+2)
    {
        if((res[i]*res[i+1])<minv)
        {
            minv = res[i]*res[i+1];
            mini = i;
        }
    }
    return {array[res[mini]],array[res[mini+1]]};
}

vector<int> FindNumbersWithSum_(vector<int> array,int sum)
{
    if(array.empty()) return {};
    int tmp = INT_MAX;
    pair<int,int> ret;
    int i = 0, j = array.size()-1;
    while (i < j)
    {
        if(array[i]+array[j]==sum)
        {
            if(array[i]*array[j]<tmp)
            {
                //star
                tmp = array[i] * array[j];
                ret = {i,j};
            }
            i++;j--;
        }
        else if(array[i]+array[j] < sum){
            i++;
        }
        else
        {
            j--;
        }
    }
    if(ret.first == ret.second) return {};
    return {array[ret.first],array[ret.second]};
    
}

int main()
{
    vector<int> array = {1,2,4,7,11,15};
    vector<int> res = FindNumbersWithSum_(array,15);
    cout << "[ ";
    for(int i:res)
    {
        cout << i << " ";
    }
    cout << " ]" << endl;
    system("pause");
    return 0;
}