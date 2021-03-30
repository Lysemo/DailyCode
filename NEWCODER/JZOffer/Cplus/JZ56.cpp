/**
 * 题目：
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
 * 重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 * 
 * 示例：
 * 输入：
 * {1,2,3,3,4,4,5}
 * 输出：
 * {1,2,5}
 */ 

#include<iostream>

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

ListNode* deleteDuplication(ListNode* pHead) 
{
    if(!pHead || !pHead->next)  //如果链表长度为0/为1 直接返回原链表
    {
        return pHead;
    }
    ListNode *pp = new ListNode(-1);    //避免第一个元素被删除，添加头节点
    pp->next = pHead;
    ListNode *f = pp;   //当前节点的父节点，用于删除当前节点后 记录后序节点
    ListNode *p1 = pHead, *p2 = pHead;  //p1记录当前节点 p2遍历后序值相同的节点，直到不一样
    while(p1)   //遍历当前节点
    {
        while(p2)   //p2遍历当前节点及后序节点
        {
            if(p2 && p1->val==p2->val)  //如果后序节点不为空  且值和当前节点值相等 p2遍历下一个节点
            {
                p2 = p2->next;
            }
            else
            {
                break;  //如果值不相同了返回
            }
        }
        if(p1->next!=p2)    //如果p2不是紧跟在p1后面，说明有重复 删除p1到p2直接的重复节点
        {
            f->next = p2;
            p1 = p2;
        }
        else    //如果p2在p1后面，说明当前元素不重复，更新f p1节点
        {
            f = p1;
            p1 = p2;
        }
    }
    return pp->next;    //返回头节点的下一个节点
}

ListNode* deleteDuplication_(ListNode* pHead)
{
    ListNode *vhead = new ListNode(-1);
    vhead->next = pHead;
    ListNode *pre = vhead, *cur = pHead;       
    while (cur) {
        if (cur->next && cur->val == cur->next->val) {
            cur = cur->next;
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            cur = cur->next;
            pre->next = cur;
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
    return vhead->next;
}

int main()
{
    ListNode *pHead = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(4);
    ListNode *n4 = new ListNode(5);
    pHead->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    ListNode *newPhead = deleteDuplication(pHead);
    ListNode *newPhead_ = deleteDuplication_(pHead);
    return 0;
}