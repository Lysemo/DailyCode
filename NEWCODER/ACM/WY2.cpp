/**
 * 题目描述：
 * 一条长l的笔直的街道上有n个路灯，若这条街的起点为0，终点为l，第i个路灯坐标为ai ，
 * 每盏灯可以覆盖到的最远距离为d，为了照明需求，所有灯的灯光必须覆盖整条街，
 * 但是为了省电，要使这个d最小，请找到这个最小的d。
 * 
 * 输入描述：
 * 每组数据第一行两个整数n和l（n大于0小于等于1000，l小于等于1000000000大于0）。
 * 第二行有n个整数(均大于等于0小于等于l)，为每盏灯的坐标，多个路灯可以在同一点。
 * 
 * 输出描述：
 * 输出答案，保留两位小数。
 * 
 * 示例：
 * 输入：
 * 7 15
 * 15 5 3 7 9 14 0
 * 输出：
 * 2.50
 */ 
#include<iostream>
#include<algorithm>

using namespace std;

/**
 * 解题思路：
 * 因为要覆盖所有的节点，因此d的最小取决于两个路灯之间最大的间隔；
 * 又因为可以两边的路灯并没有在端点处，因此将两端进行处理
 * arr[0]为第一个路灯到左端点的距离，arr[n-1]为最后一个路灯到右端点的距离，这两个距离*2，模拟下两个路灯间的距离
 * 1.先对n个路灯的位置从小到大排序
 * 2.对两个端点进行处理，谁大谁作为初始值
 * 3.对每个路灯，后一个路灯的坐标 - 前一个路灯的坐标，统计出间隔最大的
 * 4.因为路灯可以左右照，所有除2，得出最终 最小的d值
 */ 

int main()
{
    int n,l;
    while (cin>>n>>l)
    {
        int *arr = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);    //排序
        int maxDur = max(arr[0],l-arr[n-1])*2;  //两个端点的距离 大的 用于初始化
        for(int i=0;i<n-1;i++)
        {
            if((arr[i+1]-arr[i])>maxDur)    //后一个减前一个
            {
                maxDur = arr[i+1]-arr[i];   //更新最大的间距
            }
        }
        printf("%.2f\n", maxDur*1.0/2); //输出
    }
    return 0; 
}