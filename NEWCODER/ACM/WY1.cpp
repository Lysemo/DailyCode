/**
 * 题目描述：
 * 小v今年有n门课，每门都有考试，为了拿到奖学金，小v必须让自己的平均成绩至少为avg。
 * 每门课由平时成绩和考试成绩组成，满分为r。现在他知道每门课的平时成绩为ai ,
 * 若想让这门课的考试成绩多拿一分的话，小v要花bi 的时间复习，不复习的话当然就是0分。
 * 同时我们显然可以发现复习得再多也不会拿到超过满分的分数。为了拿到奖学金，
 * 小v至少要花多少时间复习。
 * 
 * 输入描述：
 * 第一行三个整数n,r,avg(n大于等于1小于等于1e5，r大于等于1小于等于1e9,avg大于等于1小于等于1e6)，
 * 接下来n行，每行两个整数ai和bi，均小于等于1e6大于等于1
 * 
 * 输出描述：
 * 一行输出答案。
 * 
 * 示例：
 * 输入：
 * 5 10 9
 * 0 5
 * 9 1
 * 8 1
 * 0 1
 * 9 100
 * 输出：
 * 43
 */ 

#include<iostream>
#include<algorithm>

using namespace std;

/**
 * 解题思想：
 * 使用贪心算法
 * 1.将每门课程的平时成绩和复习花费时间/分 捆绑
 * 2.按照复习花费时间/分 按从小到大排序
 * 3.平均分*n-总的平时成绩 就是需要复习拿到的分数
 * 4.每次先复习花费时间/分最少的，直到拿到该科目满分
 * 5.然后再复习下一个复习花费时间/分相对较少的科目
 * 6.直到复习得到的分数==需要复习拿到的分数 为止
 */ 

struct Stu
{
    int score;
    int time;
    bool operator<(const Stu &s)    //重载<运算符，按时间从小到大
    {
        return time<s.time;
    }
};

int main()
{
    int n,r,avg;
    while (cin>>n>>r>>avg)
    {
        Stu *stu = new Stu[n];
        int firstScore = 0;
        for(int i=0;i<n;i++)
        {
            cin>>stu[i].score>>stu[i].time;
            firstScore += stu[i].score;
        }
        int secondScore = n*avg - firstScore;   //需要复习拿到的总分数
        sort(stu,stu+n);    //排序
        long time = 0;  //初始化花费时间为0
        for(int i=0;i<n;i++)
        {
            if(secondScore<=0)  //如果需要复习拿到的总分数==0 退出
            {
                break;
            }
            int tmpSecondScore = r-stu[i].score;    //当前科目所能拿到的最大复习分数
            if(tmpSecondScore<=secondScore) //如果比 需要复习拿到的总分数 小   全部拿
            {
                secondScore -= tmpSecondScore;  //更新拿过后的
                time += (stu[i].time*tmpSecondScore);   //加上对应的复习时间
            }
            else    //说明 在该科目上只能拿部分分
            {
                time += (stu[i].time*secondScore);
                secondScore = 0;    //更新为0
            }
            
        }
        cout << time << endl;
    }
    return 0;
    
}