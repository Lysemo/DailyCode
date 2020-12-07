/**
 * 
 * 题目：
 * 输入一个链表，反转链表后，输出新链表的表头。
 * 
 * 示例：
 * 输入：
 * {1,2,3}
 * 输出：
 * {3,2,1}
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

ListNode* ReverseList(ListNode* pHead) {
    ListNode* pre = nullptr;
    ListNode* cur = pHead;
    ListNode* tmp = nullptr;
    while(cur){
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

int main(){
    ListNode* pHead = new ListNode(1);
    ListNode* p = pHead;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = pHead;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << " " << endl;
    ListNode* nHead = ReverseList(pHead);
    p = nHead;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << " " << endl;
    system("pause");
    return 1;
}