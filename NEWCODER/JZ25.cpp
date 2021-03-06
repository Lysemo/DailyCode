/**
 * 
 * 题目：
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），
 * 请对此链表进行深拷贝，并返回拷贝后的头结点。
 * （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

// import java.util.HashMap;

// public class Solution {
//     public RandomListNode Clone(RandomListNode pHead) {
//         if (pHead == null) return null;

//             // target 作为将要返回的头，记住要new的
//             RandomListNode target = new RandomListNode(pHead.label);
//             // cur 获取链表头
//             RandomListNode cur = pHead;
//             // p   获取新链表头
//             RandomListNode p = target;

//             HashMap<RandomListNode, RandomListNode> map = new HashMap<>();

//             // 由pHead将所有值存入map，每一个结点都要new的
//             while (pHead != null) {
//                 map.put(pHead, new RandomListNode(pHead.label));
//                 pHead = pHead.next;
//             }

//             // target作为新链表的头，由cur，p移动来复制链表
//             while (cur != null) {
//                 p.next = map.get( cur.next );
//                 p.random = map.get( cur.random );

//                 cur = cur.next;
//                 p = p.next;
//             }

//             return target;
//     }
// }


RandomListNode* Clone(RandomListNode* pHead)
{
    vector<RandomListNode*> node1;  // 记录原始链表已存在的结点
    vector<RandomListNode*> node2;  // 记录新链表已存在的结点
    RandomListNode *nHead = new RandomListNode(-1); // 生成虚拟结点
    RandomListNode *r = nHead;
    while(pHead){
        int flg1 = -1,flg2 = -1;
        //判断该节点是否已存在，若已存在，则直接使用，否则，新建；
        for(int i=0;i<node1.size();i++){
            if(pHead==node1[i]){
                flg1 = i;
            }
            if(pHead->random && pHead->random==node1[i]){
                flg2 = i;
            }
        }
        if(flg1!=-1) nHead->next = node2[flg1];
        else{
            nHead->next = new RandomListNode(pHead->label);
            node1.push_back(pHead);
            node2.push_back(nHead->next);
        }
        if(flg2!=-1) nHead->next->random = node2[flg2];
        else{
            if(pHead->random){
                nHead->next->random = new RandomListNode(pHead->random->label);
                node2.push_back(nHead->next->random);
                node1.push_back(pHead->random);
            }
        }
        pHead = pHead->next;
        nHead = nHead->next;
    }
    return r->next;
}

RandomListNode* Clone_(RandomListNode* pHead){
    if(!pHead) return nullptr;
    RandomListNode *curN = pHead;
    while (curN)
    {
        RandomListNode *cloN = new RandomListNode(curN->label);
        RandomListNode *nexN = curN->next;
        curN->next = cloN;
        cloN->next = nexN;
        curN = nexN;
    }
    curN = pHead;
    while (curN)
    {
        curN->next->random = curN->random==nullptr?nullptr:curN->random->next;
        curN = curN->next->next;
    }
    curN = pHead;
    RandomListNode *cloHead = pHead->next;
    while (curN)
    {
        RandomListNode *cloN = curN->next;
        curN->next = cloN->next;
        cloN->next = cloN->next==nullptr?nullptr:cloN->next->next;
        curN = curN->next;
    }
    return cloHead;  
}

int main(){
    vector<RandomListNode*> nodes;
    RandomListNode *root = new RandomListNode(1);
    nodes.push_back(root);
    root->next = new RandomListNode(2);
    nodes.push_back(root->next);
    root->next->next = new RandomListNode(3);
    nodes.push_back(root->next->next);
    root->next->next->next = new RandomListNode(4);
    nodes.push_back(root->next->next->next);
    RandomListNode *p = root;
    while (p)
    {
        p->random = nodes[rand()%4];
        p = p->next;
    }
    RandomListNode *nRoot1 = Clone(root);
    RandomListNode *nRoot2 = Clone_(root);
    return 1;
}