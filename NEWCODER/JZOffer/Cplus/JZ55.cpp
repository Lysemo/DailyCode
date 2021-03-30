/**
 * 题目：
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null
 * 
 */ 

#include<iostream>
#include<set>

using namespace std;

struct ListNode
{
    ListNode(int v)
        :val(v)
        ,next(nullptr)
    {}
    int val;
    ListNode* next;
};


ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if(pHead==nullptr)
    {
        return nullptr;
    }
    set<ListNode*> set1;
    ListNode *p = pHead;
    while(p)
    {
        if(set1.find(p)!=set1.end())
        {
            return p;
        }
        set1.insert(p);
        p = p->next;
    }
    return nullptr;
}

//快慢指针法
/*
1.初始化：快指针fast指向头结点， 慢指针slow指向头结点
2.让fast一次走两步， slow一次走一步，第一次相遇在C处，停止
3.然后让fast指向头结点，slow原地不动，让后fast，slow每次走一步，当再次相遇，就是入口结点
*/
ListNode* EntryNodeOfLoop_(ListNode* pHead) 
{
    ListNode* fast = pHead;
    ListNode* slow = pHead;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) break;
    }
    if(!fast || !fast->next)
    {
        return nullptr;
    }
    fast = pHead;
    while(fast!=slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

int main()
{
    ListNode *pHead = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    pHead->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;
    ListNode* p = EntryNodeOfLoop(pHead);
    if(p!=nullptr)
    {
        cout << p->val << endl;
    }
    else
    {
        cout << "no no no" << endl;
    }
    system("pause");
    return 0;
}