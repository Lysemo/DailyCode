/**
 * 
 * 题目：
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组,求出这个数组中的逆序对的总数P。
 * 并将P对1000000007取模的结果输出。 即输出P%1000000007
 * 对于50%的数据,size≤1e4
 * 对于75%的数据,size≤1e5
 * 对于100%的数据,size≤2e5
 * 输入描述：题目保证输入的数组中没有的相同的数字
 * 
 * 示例：
 * 输入：
 * [1,2,3,4,5,6,7,0]
 * 输出：
 * 7
 */ 

#include<iostream>
#include<vector>

using namespace std;

int InversePairs(vector<int> data) {
    if(data.empty()) return 0;
    long long cnt = 0;
    for(int i=0;i<data.size()-1;i++){
        for(int j=i+1;j<data.size();j++){
            if(data[i]>data[j]) cnt++;
        }
    }
    int ans = int(cnt%1000000007);
    return ans;
}
void merge__(vector<int> &arr,vector<int> &tmp,int l,int mid,int r,int &ret){
    int i=l,j=mid+1,k=0;
    while (i<=mid && j<=r){
        if(arr[i] > arr[j]){
            tmp[k++] = arr[j++];
            ret += (mid-i+1);
            ret %= 1000000007;
        }
        else
        {
            tmp[k++] = arr[i++];
        }
    }
    while (i<=mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j<=r)
    {
        tmp[k++] = arr[j++];
    }
    for(k=0,i=l;i<=r;++i,++k){
        arr[i] = tmp[k];
    }  
}

void merge_sort__(vector<int> &arr,vector<int> &tmp,int l,int r,int &ret){
    if(l >= r) return;
    int mid = l + ((r-l)>>1);
    merge_sort__(arr,tmp,l,mid,ret);
    merge_sort__(arr,tmp,mid+1,r,ret);
    merge__(arr,tmp,l,mid,r,ret);
}

int InversePairs_(vector<int> data){
    int ret = 0;
    vector<int> tmp(data.size());
    merge_sort__(data,tmp,0,data.size()-1,ret);
    return ret;
}

int main(){
    vector<int> data = {7,6,5,4,3,2,1,0};
    cout << InversePairs_(data) << endl;
    system("pause");
    return 0;
}