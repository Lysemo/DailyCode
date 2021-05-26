/*
[题目描述]
如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
{1, 2, 1}, {15, 78, 78, 15}, {112} 是回文序列,
{1, 2, 2}, {15, 78, 87, 51}, {112, 2, 11} 不是回文序列。
现在给出一个数字序列，允许使用一种转换操作：
选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。

[示例]
输入：
4
1 1 1 3
输出：
2

[说明]
经过第一次操作后，变为2 1 3，{2, 1, 3} 不是回文序列；
再经过一次操作后，变为3 3，{3, 3} 是回文序列；
所以共需要进行两次转换。  
*/

#include<iostream>

using namespace std;

/*
解题思想：
使用双指针left,right，初始分别指向数组第一个元素和最后一个元素
如果left<right时：
判断：
如果arr[left]==arr[right],left++;right--;
如果arr[left]>arr[right],先让arr[right-1]+arr[right],然后right--；
如果arr[left]<arr[right],先让arr[left+1]+arr[left],然后left++；
*/

int main()
{
    int n;
    while(cin>>n)
    {
        int *arr = new int[n];
        int num = 0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int left = 0;
        int right = n-1;
        while(left<right)
        {
            if(arr[left]==arr[right])
            {
                left++;
                right--;
            }
            else if(arr[left]>arr[right])
            {
                arr[right-1] += arr[right];
                right--;    //模拟 先将两个相邻数取出来，加和，再放进去
                num++;
            }
            else
            {
                arr[left+1] += arr[left];
                left++;
                num++;
            }
        }
        cout << num << endl;
    }
    return 0;
}