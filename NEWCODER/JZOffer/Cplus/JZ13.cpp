/**
 * 
 * 题目：
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>

using namespace std;

//时间占用3ms | 内存占用492k
void reOrderArray(vector<int> &array) {
    for(int i=0;i<array.size()-1;i++){
        int flg = -1;
        for(int j=0;j<array.size();j++){
            if(array[j]%2==0 && array[j+1]%2==1){
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                flg = 0;
            }
        }
        if(flg!=0) break;
    }
}

//时间占用3ms | 内存占用484k
void reOrderArray_(vector<int> &array) {
    int i = 0;
    for(int j=0;j<array.size();j++){
        if(array[j]&1){
            int tmp = array[j];
            for(int k=j-1;k>=i;k--){
                array[k+1] = array[k];
            }
            array[i++] = tmp;
        }
    }
}

void reOrderArray__(vector<int> &array) {
    vector<int> arr;
    for(const int v : array){
        if(v&1) arr.push_back(v);
    }
    for(const int v: array){
        if(!(v&1)) arr.push_back(v);
    }
    copy(arr.begin(),arr.end(),array.begin());
}

int main(){
    int a[] = {2,4,6,1,3,5,7};
    vector<int> array(a,a+7);
    // reOrderArray__(array);
    // reOrderArray_(array);
    reOrderArray(array);
    for(int i=0;i<array.size();i++)
        cout << array[i] << " ";
    system("pause");
    return 1;
}