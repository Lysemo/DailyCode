/**
 * 
 * 题目：
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

void midOrder(TreeNode *root,queue<TreeNode*> &q){
    if(root->left) midOrder(root->left,q);
    q.push(root);
    if(q.size()==2){
        q.front()->right = q.back();
        q.back()->left = q.front();
        q.pop();
    }
    if(root->right) midOrder(root->right,q);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
    if(!pRootOfTree) return nullptr;
    queue<TreeNode*> q;
    TreeNode *p = pRootOfTree;
    while (p->left)
    {
        p = p->left;
    }
    midOrder(pRootOfTree,q);
    return p;
}

int main(){
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(12);
    TreeNode *nRoot = Convert(root);
    TreeNode *p = nRoot;
    while (p)
    {
        cout << p->val << " ";
        p = p->right;
    }
    cout << " " << endl;
    system("pause");
}