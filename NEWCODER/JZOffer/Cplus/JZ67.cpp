/**
 * 题目：
 * 给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1，m<=n），
 * 每段绳子的长度记为k[1],...,k[m]。请问k[1]x...xk[m]可能的最大乘积是多少？
 * 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 * 
 * 输入描述：输入一个数n，意义见题面。（2 <= n <= 60）
 * 
 * 示例：
 * 输入：
 * 8
 * 输出：
 * 18
 * 
 */ 
#include<iostream>
#include<vector>

using namespace std;

class Solution1 
{
public:
    int back_track(int n) {
        // n <= 4, 表明不分，长度是最大的
        if (n <= 4) {
            return n;
        }
 
        int ret = 0;
        for (int i = 1; i < n; ++i) {
            ret = max(ret, i * back_track(n - i));
        }
        return ret;
    }
    int cutRope(int number) {
        // number = 2 和 3 时，分 2 段和分 1 段的结果是不一样的，所以需要特判一下
        if (number == 2) {
            return 1;
        }
        else if (number == 3) {
            return 2;
        }
        return back_track(number);
    }
};

// ---------------------------------------------------------------

class Solution2 
{
public:
    int back_track(int n, vector<int> &mark) {
        if (n <= 4) {
            return n;
        }
        // 在方法一的基础上添加 避免重复计算
        if (mark[n] != -1) {
            return mark[n];
        }

        int ret = 0;
        for (int i = 1; i < n; ++i) {
            ret = max(ret, i * back_track(n - i,mark));
        }
        // 添加部分
        return mark[n] = ret;
    }
    int cutRope(int number) {
        if (number == 2) {
            return 1;
        }
        else if (number == 3) {
            return 2;
        }
        // 添加部分
        vector<int> mark(number+1, -1);

        return back_track(number, mark);
    }
};

// ---------------------------------------------------------------
class Solution3 
{
public:
    int cutRope(int number) 
    {
        if(number==2)   //1*1
        {
            return 1;
        }
        else if(number==3)  //1*2
        {
            return 2;
        }
        
        vector<int> f(number+1,-1);
        for(int i = 1;i<=4;i++) //初始条件  这几个长度 不分割  乘积最大
        {
            f[i] = i;
        }
        for(int i = 5;i<=number;i++)
        {
            for(int j=1;j<=i/2;j++)
            {
                f[i] = max(f[i],j*f[i-j]);
            }
        }
        return f[number];
    }
};

int main()
{
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    cout << s1.cutRope(8) << endl;
    cout << s2.cutRope(8) << endl;
    cout << s3.cutRope(8) << endl;
    system("pause");
    return 0;
}