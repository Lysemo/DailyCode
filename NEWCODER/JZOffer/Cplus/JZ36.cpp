#include<iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if(pHead1==nullptr || pHead2==nullptr) return nullptr;
    ListNode *ta = pHead1, *tb = pHead2;
    while(ta != tb){
        ta = ta?ta->next:pHead2;
        tb = tb?tb->next:pHead1;
    }
    return ta;
}

int main(){
    ListNode *pHead1 = new ListNode(3);
    ListNode node(1);
    ListNode *pHead2 = new ListNode(3);
    pHead1->next = new ListNode(2);
    pHead1->next->next = &node;
    pHead2->next = &node;
    ListNode *ret = FindFirstCommonNode(pHead1,pHead2);
    cout << ret->val << endl;
    system("pause");
    return 0;
}