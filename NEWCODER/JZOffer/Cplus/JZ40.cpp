/**
 * 
 * 题目：
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字
 * 说明：返回的结果中较小的数排在前面  
 * 
 * 示例：
 * 输入：
 * [1,4,1,6]
 * 输出：
 * [4,6]
 * 
 */ 

#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> FindNumsAppearOnce(vector<int>& array) {
    // write code here
    vector<int> ret;
    map<int,int> mp;
    for(int v:array) mp[v]++;
    for(map<int,int>::iterator iter = mp.begin();iter!=mp.end();iter++){
        if(iter->second==1)
            ret.push_back(iter->first);
    }
    if(ret[0]>ret[1])
    {
        int tmp = ret[0];
        ret[0] = ret[1];
        ret[1] = tmp;
    }
    return ret;
}

/*
异或概念：对数组中所有数组进行异或（^）,异或异或是强调异，即相同为0不同为1。
        相同两数异或为0，0与任何一个数异或为个该数本身。且异或符合交换律。
        所以题目中数组所有数字异或后结果为两个不同的数进行异或。（设为a^b）
异或后，从后往前(个位->十位方向)，找到他们二进制中第一个为1的位置，该位置上两个数的二进制不一样否则不可能为1.（设该位置为k）为了划分出来两个数。
然后重新对数组异或，但是在异或的时候，根据该位置（k上为1和0）来划分，
    最后会将这两数字划分开来。虽然其他的数也会划分开来，但是他们是成对划分的，无论在那边都不影响最后结果
*/
vector<int> FindNumsAppearOnce_(vector<int>& array) {
        // 当出现成对相同数据时 可考虑使用
        // 当出现唯一2个不同的数据时 可考虑使用
        // ^ 按位异或
        // & 按位与
        // ~ 按位非
        // | 按位或
        // 优先级： ~、&、^、|
        // << 左移 相当于乘以2^n
        // >> 右移 相当于除以2^n
        vector<int> ans(2);
        int res = 0;
        for(int x : array)
        {
            res ^= x;
        }
        int m = 1;
        while(!(m & res)) m <<= 1;
        for(int x : array)
        {
            if(!(m & x)) ans[0] ^= x;
            else ans[1] ^= x;
        }
        if(ans[0]>ans[1]) swap(ans[0],ans[1]);
        return ans;
    }

int main()
{
    vector<int> arr = {1,2,1,3};
    vector<int> res = FindNumsAppearOnce(arr);
    vector<int> res_ = FindNumsAppearOnce_(arr);
    cout << res[0] << " " << res[1] << endl;
    cout << res_[0] << " " << res_[1] << endl;
    system("pause");
    return 1;
}