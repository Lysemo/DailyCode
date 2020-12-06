/**
 * 
 * 题目：
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 32M，其他语言64M
 * 
*/ 

#include<stack>
#include<iostream>

using namespace std;

class Solution
{
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    void push(int node){
        stack1.push(node);
    }
    int pop(){
        if(stack1.empty()){
            cout << "no element";
            return -1010;
        }
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int tmp = stack2.top();
        stack2.pop();
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return tmp;
    }
};

int main(){
    Solution list;
    list.push(1);
    list.push(2);
    list.push(3);
    cout << list.pop() << " ";
    cout << list.pop() << " ";
    cout << list.pop() << " ";
    system("pause");
    return 1;
}
