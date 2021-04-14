#include<iostream>
#include<vector>

using namespace std;
/*
快速排序算法：
1.选取pivot，作为主值
2.所有大于pivot的数，放到pivot的右边
3.所有小于pivot的数，放到pivot的左边
4.对pivot左右两边的子序列，分别进行1，2，3操作，当子序列长度为1时，直接返回；
*/
void fastSort(vector<int> &arr,int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int pv = arr[left];
    int cleft = left,cright = right;
    while (left<right)
    {
        while (left<right && arr[right]>=pv)
        {
            right--;
        }
        if(left<right)
        {
            arr[left] = arr[right];
            left++;
        }
        while (left<right && arr[left]<=pv)
        {
            left++;
        }
        if(left<right)
        {
            arr[right] = arr[left];
            right--;
        }
        if(left>=right)
        {
            arr[left] = pv;
        }
    }
    fastSort(arr,cleft,left-1);
    fastSort(arr,left+1,cright);
}

int main()
{
    vector<int> arr = {10,2,4,3,5,7,1,9};
    fastSort(arr,0,arr.size()-1);
    return 0;
}