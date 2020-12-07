/**
 * 
 * 题目：
 * 输入一个链表，输出该链表中倒数第k个结点。
 * 示例：
 * 输入：
 * 1,{1,2,3,4,5}
 * 输出：
 * {5}
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M 
 */

#include<iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

//时间占用3ms | 内存占用376ms
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    int len = 0;
    ListNode* p = pListHead;
    while(p){
            len++;
        p = p->next;
    }
    p = pListHead;
    int i = 0;
    while(p){
        i++;
        if((len-i+1)==(int)k)
            return p;
        p = p->next;
    }
    return nullptr;
}

int main(){
    ListNode* pListHead = new ListNode(1);
    ListNode* p = pListHead;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    cout << FindKthToTail(pListHead,2)->val << endl;
    system("pause");
    return 1;
}