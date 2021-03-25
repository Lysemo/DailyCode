/**
 * 题目：
 * LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
 * 他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
 * “红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,
 * 并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
 * LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 
 * 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
 * 
 * 示例：
 * 输入：
 * [0,3,2,6,4]
 * 输出：
 * true
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool IsContinuous( vector<int> numbers ) 
{
    if(numbers.empty()) return false;   //如果数组为空，直接返回false
    vector<int> tmp;
    for(int v : numbers)    //统计非0的个数
    {
        if(v!=0)
        {
            tmp.push_back(v);
        }
    }
    if((numbers.size()-tmp.size())>=4)  //如果0的个数为4 / 5，则一定能组成顺子
    {
        return true;
    }
    for(int i=0;i<tmp.size()-1;i++) //冒泡排序 非0的数
    {
        int flg = 0;
        for(int j=0;j<tmp.size()-i-1;j++)
        {
            if(tmp[j]>tmp[j+1])
            {
                int tt = tmp[j];
                tmp[j] = tmp[j+1];
                tmp[j+1] = tt;
                flg = 1;
            }
        }
        if(flg==0)
        {
            break;
        }
    }
    int ss = 0;
    for(int i = 0;i<tmp.size()-1;i++)
    {
        if((tmp[i+1]-tmp[i])==0)    //如果非0数里面有相等的，则不可能是顺子
        {
            return false;
        }
        ss += (tmp[i+1]-tmp[i]-1);  //统计相邻非0数字之间的差值和，该和的个数 为 想组成顺子时 0的个数
        if(ss > (numbers.size()-tmp.size()))    //如果 相邻非0数字之间的差值和 > 0的个数，则不能组成顺子
        {
            return false;
        }
    }
    return true;    //否则可以组成顺子
}

bool IsContinuous_( vector<int> numbers ) 
{
    if(numbers.empty()) return false;
    sort(numbers.begin(),numbers.end());    //排序
    int i=0,sz = numbers.size();
    for(int j=0;j<sz;j++)
    {
        if(numbers[j]==0)   //记录最小非0的数的索引
        {
            i++;
            continue;
        }
        if(j+1<sz && numbers[j] == numbers[j+1])    //如果存在重复，不会是顺子
        {
            return false;
        }
    }
    return numbers.back()-numbers[i]<5; //最大值-最小值<5 就是顺子 否则不为顺子
}

int main()
{
    cout << IsContinuous({0,3,2,6,4}) << endl;
    cout << IsContinuous_({0,3,2,6,4}) << endl;
    system("pause");
    return 0;
}