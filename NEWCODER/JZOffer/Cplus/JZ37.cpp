/**
 * 
 * 题目：
 * 统计一个数字在升序数组中出现的次数。
 * 
 * 示例：
 * 输入：
 * [1,2,3,3,3,3,4,5],3
 * 输出：
 * 4
 * 
 */ 

#include<iostream>
#include<vector>

using namespace std;

void biSearch(vector<int> arr,int target, int l,int r,int &ret){
    if(l>=r) {if(arr[l]==target) {ret++; return;}}
    int mid = l + ((r-l)>>1);
    if(target < arr[mid]){
        biSearch(arr, target, l, mid-1, ret);
    }else if(target > arr[mid]){
        biSearch(arr, target, mid+1, r, ret);
    }else{
        int i = mid;
        while(arr[i]==target){
            ret++;
            if((i-1)<l) break;
            i--;
        }
        i = mid+1;
        if(i<=r){
            while(arr[i]==target){
                ret++;
                if((i+1)>r) break;
                i++;
            }
        }
    }
}
int GetNumberOfK(vector<int> data ,int k) {
    int ret = 0;
    if(data.empty() || k<data[0] || k>data[data.size()-1]) return ret;
    // 递归二分查找 内存占用大
    biSearch(data, k, 0, data.size()-1, ret);
    return ret;
}

int GetNumberOfK_(vector<int> data ,int k) {
    if(data.empty() || k<data[0] || k>data[data.size()-1]) return 0;
    int left = 0,right = data.size()-1,count=0,mid=-1;
    // 非递归二分查找，效率较高
    while(left<right)
    {
        mid = (left+right)/2;
        if(data[mid]>k) right = mid - 1;
        else if(data[mid]<k) left = mid + 1;
        else {count++;break;}
    }
    int prev = mid - 1;
    int foll = mid + 1;
    while(prev >=left)
    {
        if(data[prev]==k)
        {
            count++;
            prev--;
        }
        else break;
    }
    while(foll<=right)
    {
        if(data[foll] == k)
        {
            count++;
            foll++;
        }
        else break;
    }
    return count;
}

int GetNumberOfK__(vector<int> nums ,int target) 
{
    int lbound = 0, rbound = 0;
    // 寻找上界
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    lbound = l;
    // 寻找下界
    l = 0, r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] <= target) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    rbound = l;
    return rbound - lbound;
}

int main()
{
    vector<int> arr = {0,1,2,3,4,5};
    int num = GetNumberOfK__(arr,1);
    cout << num << endl;
    system("pause");
    return 0;
}