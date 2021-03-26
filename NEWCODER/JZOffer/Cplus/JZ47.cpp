/**
 * 题目：
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
 * 
 * 示例：
 * 输入：
 * 5
 * 输出：
 * 15
 * 
 */
#include<iostream>

using namespace std;

//短路原理
/*
如果 && 运算符左侧的子表达式为 false，则不会检查右侧的表达式。
因为只要有一个子表达式为 false，则整个表达式都为 false，
所以再检查剩余的表达式会浪费 CPU 时间。这被称为短路评估
----------------------------------------------------
|| 运算符也将进行短路评估。
如果 || 运算符左侧的子表达式为 true，
则右侧的子表达式将不被检查，
因为只要有一个子表达式为 true，那么整体表达式就可以被评估为 true
*/

int Sum_Solution(int n) {
    int sum = n;
    sum && (sum+=Sum_Solution(n-1));
    return sum;
}

int Sum_Solution_(int n) {
    int sum = n;
    sum==1 || (sum+=Sum_Solution(n-1));
    return sum;
}

int main()
{
    cout << Sum_Solution(5) << endl;
    cout << Sum_Solution_(5) << endl;
    system("pause");
    return 0;
}