#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};

vector<int> printListFromTailToHead(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* tmp = cur;
    while (cur)
    {
        tmp = cur->next;      //先保存反转节点的下一个指向节点，不然就断了；
        cur->next = pre;      //反向指向前一个节点
        pre = cur;            //更新前一个节点
        cur = tmp;            //更新反转节点
    }
    vector<int> res;
    while (pre)
    {
        res.push_back(pre->val);
        pre = pre->next;
    }
    return res;
}

int main(){
      ListNode* head = new ListNode(1);
      ListNode* p = head;
      vector<int> res;
      p->next = new ListNode(2);
      p = p->next;
      p->next = new ListNode(3);
      p = p->next;
      p->next = new ListNode(4);
      res = printListFromTailToHead(head);
      for(int i=0;i<res.size();i++){
            cout << res[i] << " ";
      }
      system("pause");
      return 1;
}