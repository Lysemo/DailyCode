/**
 * 
 * 题目：
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0
 * 
 * 示例：
 * 输入：
 * [3,4,5,1,2]
 * 输出：
 * 1
 * 
 * 要求：
 * 时间限制：C/C++ 3秒，其他语言6秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<vector>
#include<iostream>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.empty())
        return 0;
    int first = 0, last = rotateArray.size()-1;
    while(first < last){
        if(rotateArray[first] < rotateArray[last])
            return rotateArray[first];
        int mid = first + int((last - first)/2);
        if(rotateArray[mid]>rotateArray[last])
            first = mid + 1;
        else if(rotateArray[mid]<rotateArray[last])
            last = mid;
        else
            last--;
    }
    return rotateArray[first];
}

int main(){
    int a[] = {3,4,5,1,2};
    vector<int>  rotateArray(a,a+5);
    cout<<minNumberInRotateArray(rotateArray)<<endl;
    system("pause");
}