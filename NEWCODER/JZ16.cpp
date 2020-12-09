/**
 * 
 * 题目：
 * 输入两个单调递增的链表，输出两个链表合成后的链表，
 * 当然我们需要合成后的链表满足单调不减规则
 * 
 * 示例：
 * 输入：
 * {1,3,5},{2,4,6}
 * 输出：
 * {1,2,3,4,5,6}
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

//2ms | 484k
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* newHead = nullptr, *curs = nullptr, *pres = nullptr;
    ListNode* q = nullptr;
    if(!pHead1 && !pHead2) return nullptr;
    if(!pHead1 && pHead2) return pHead2;
    if(pHead1 && !pHead2) return pHead1;
    if(pHead1->val > pHead2->val){
        pres = newHead = pHead2;
        curs = pHead2->next;
        q = pHead1;
    }else{
        pres = newHead = pHead1;
        curs = pHead1->next;
        q = pHead2;
    }
    if(!curs){
        pres->next = q;
        return newHead;
    }
    while(q){
        ListNode *pre = pres;
        ListNode *cur = pre->next;

        ListNode* node = q;
        ListNode* tmp1 = q->next;
        q->next = nullptr;
        q = tmp1;
        while(cur){
            if(node->val<=cur->val){
                pre->next = node;
                node->next = cur;
                break;
            }
            else if(!(cur->next)){
                cur->next = node;
                break;
            }
            else if(node->val>cur->val && node->val<=cur->next->val){
                ListNode* tmp2 = cur->next;
                cur->next = node;
                node->next = tmp2;
                break;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
    }
    return newHead;
}

ListNode* Merge_(ListNode* pHead1, ListNode* pHead2){
    ListNode* vhead = new ListNode(-1);
    ListNode* cur = vhead;
    while (pHead1 && pHead2)
    {
        if(pHead1->val<=pHead2->val){
            cur->next = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            cur->next = pHead2;
            pHead2 = pHead2->next;
        }
        cur = cur->next;
    }
    cur->next = pHead1? pHead1:pHead2;
    return vhead->next;
}

ListNode* Merge__(ListNode* pHead1, ListNode* pHead2){
    if(!pHead1) return pHead2;
    if(!pHead2) return pHead1;
    if(pHead1->val<=pHead2->val){
        pHead1->next = Merge(pHead1->next,pHead2);
        return pHead1;
    }else
    {
        pHead2->next = Merge(pHead1,pHead2->next);
        return pHead2;
    } 
}

int main(){
    ListNode* pHead1 = new ListNode(1);
    pHead1->next = new ListNode(3);
    pHead1->next->next = new ListNode(5);

    ListNode* pHead2 = new ListNode(2);
    pHead2->next = new ListNode(4);
    pHead2->next->next = new ListNode(6);

    ListNode* p = pHead1;
    while (p)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout << " " << endl;

    p = pHead2;
    while (p)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout << "" << endl;
    // ListNode* newHead = Merge(pHead1,pHead2);
    // ListNode* newHead = Merge_(pHead1,pHead2);
    ListNode* newHead = Merge__(pHead1,pHead2);
    while (newHead)
    {
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    cout << "" << endl;
    system("pause");
    return 1;
}