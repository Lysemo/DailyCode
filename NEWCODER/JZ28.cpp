/**
 * 
 * 题目：
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，
 * 因此输出2。如果不存在则输出0。
 * 
 * 示例：
 * 输入：
 * [1,2,3,2,2,2,5,4,2]
 * 输出：
 * 2
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    int start=0,stop=numbers.size()-1,pre;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]!=pre){
            start = i;
        }
        pre = numbers[i];
        stop = i;
        if((i-start+1)>(numbers.size()/2))
            return numbers[i];
    }
    return 0;
}

int MoreThanHalfNum_Solution_(vector<int> numbers) {
    int cond = -1;
    int cnt = 0;
    //寻找候选众数
    for(int i=0;i<numbers.size();i++){
        if(cnt==0){
            cond = numbers[i];
            cnt++;
        }
        else
        {
            if(cond == numbers[i]) cnt++;
            else cnt--;
        }
    }
    for(const int k : numbers){
        if(cond == k) cnt++;
    }
    if(cnt > numbers.size()/2) return cond;
    return 0;
}
int main(){
    int a[] = {1,2,3,2,2,2,5,4,2};
    vector<int> num(a,a+9);
    cout << MoreThanHalfNum_Solution(num) << endl;
    system("pause");
}