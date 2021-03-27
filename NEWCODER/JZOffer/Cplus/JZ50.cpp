/**
 * 题目：
 * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，
 * 但不知道有几个数字是重复的。也不知道每个数字重复几次。
 * 请找出数组中任一一个重复的数字。 例如，如果输入长度为7的数组[2,3,1,0,2,5,3]，
 * 那么对应的输出是2或者3。存在不合法的输入的话输出-1
 * 
 * 示例：
 * 输入：
 * [2,3,1,0,2,5,3]
 * 输出：
 * 2或者3
 * 
 */ 
#include<iostream>
#include<vector>
#include<set>

using namespace std;

int duplicate(vector<int>& numbers) 
{
    // write code here
    if(numbers.empty()) return -1;
    set<int> set1;
    for(int v:numbers)
    {
        auto it = set1.find(v);
        if(it!=set1.end())
        {
            return *it;
        }
        else
        {
            set1.insert(v);
        }
    }
    return -1;
}

int duplicate_(vector<int>& numbers) 
{
    // write code here
    if(numbers.empty()) return -1;
    vector<int> count(numbers.size());
    for(int v:numbers)
    {
        count[v]++; //由于数字中的值为0 ~ n-1之间，因此可以作为下标来统计每个数字出现的次数
        if(count[v]>1)  //如果次数大于1，返回下标数字;每次都判断，可以提前结束
        {
            return v;
        }
    }
    return -1;  //如果都不重复，返回-1
}

int main()
{
    vector<int> numbers = {2,3,1,0,2,5,3};
    cout << duplicate(numbers) << endl;
    cout << duplicate_(numbers) << endl;
    system("pause");
    return 0;
}