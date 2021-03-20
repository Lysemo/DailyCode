/**
 * 
 * 题目：
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<stack>

using namespace std;
class Solution {
public:
    stack<int> normal, minval;
    void push(int value) {
        normal.push(value);
        if(minval.empty()){
            minval.push(value);
        }
        else{
            if(value<=minval.top()){
                minval.push(value);
            }
            else{
                minval.push(minval.top());
            }
        }
    }
    void pop() {
        normal.pop();
        minval.pop();
    }
    int top() {
        return normal.top();
    }
    int min() {
        return minval.top();
    }
};

int main(){
    Solution s;
    s.push(4);s.push(2);s.push(3);s.push(1);
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    system("pause");
    return 1;
}