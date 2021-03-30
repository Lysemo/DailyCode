/**
 * 题目：
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 * 
 */ 
#include<iostream>
#include<stack>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {   
    }
};

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if(pNode==nullptr) return nullptr;
    TreeLinkNode* root = pNode;
    while(root->next)   //先根据给出的节点 找到根节点
    {
        root = root->next;
    }
    stack<TreeLinkNode*> s;
    TreeLinkNode* cur = root->left; //将根节点的左孩子赋值给cur节点
    s.push(root);   //根节点入栈
    bool flg = false;   //判断是否出现了目标节点
    while(!s.empty() || cur!=nullptr)   //当前栈非空 或者 左孩子非null 循环
    {
        if(cur!=nullptr)    //如果存在左孩子
        {
            s.push(cur);    //左孩子入栈
            cur = cur->left;    //cur指向cur->left
        }
        else    //如果再没有左孩子，弹出栈顶元素
        {
            TreeLinkNode *n = s.top();
            s.pop();
            if(flg) //看是否出现过目标元素 如果出现 返回下一个元素
            {
                return n;
            }
            if(n==pNode)    //如果出现给定的元素 flg置为true
            {
                flg = true;
            }
            
            cur = n->right; //cur指向n->right 再对cur节点作为根节点 一直入左孩子
        }
    }
    return nullptr; //如果没提前入 说明目标节点后面没元素
}

/*
根据中序遍历的规则，当结点存在右子树的时候，中序遍历的下一个结点为右子树的最左节点。
但是当节点不存在右子树的时候，中序遍历的下一个结点必定为该节点的父辈节点。但是究竟是哪一辈呢？

根据中序遍历特性，左父结点一定已经被中序遍历访问过，
所以下一个结点一定是在父节点路径上的第一个右父节点
*/
TreeLinkNode* GetNext_(TreeLinkNode* pNode) 
{
    if(pNode==nullptr)  //如果pNode为空 返回为空
    {
        return nullptr;
    }
    if(pNode->right!=nullptr)   //如果有右节点 中序遍历的下一个节点 一定是右节点或右节点的左孩子（到头）
    {
        pNode = pNode->right;
        while(pNode->left!=nullptr)
        {
            pNode = pNode->left;
        }
        return pNode;
    }
    while(pNode->next!=nullptr) //如果没右节点，则下一个节点在他的父节点处 但在那一辈 不确定
    {  
        //如果它是它父亲的右孩子 它父亲一定访问过
        if(pNode->next->left==pNode)    //如果某一辈父节点的左孩子是pNode 当pNode访问过  他的父亲一定没访问过
        {
            return pNode->next;
        }
        pNode = pNode->next;
    }
    return nullptr;
}

int main()
{
    TreeLinkNode *n1 = new TreeLinkNode(1);
    TreeLinkNode *n2 = new TreeLinkNode(2);
    TreeLinkNode *n3 = new TreeLinkNode(3);
    TreeLinkNode *n4 = new TreeLinkNode(4);
    TreeLinkNode *n5 = new TreeLinkNode(5);
    n1->left = n2;
    n1->right = n3;
    n2->next = n1;
    n3->next =n1;
    n2->left = n4;
    n4->next = n2;
    n3->right = n5;
    n5->next = n3;
    TreeLinkNode *t = GetNext(n5);
    TreeLinkNode *t_ = GetNext_(n4);
    if(t!=nullptr)
    {
        cout << t->val << endl;
    }
    else
    {
        cout << "no no " << endl;
    }
    if(t_!=nullptr)
    {
        cout << t_->val << endl;
    }
    else
    {
        cout << "no no " << endl;
    }
    system("pause");
    return 0;
}