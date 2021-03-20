/**
 * 
 * 题目：
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
 * 
 * 示例：
 * 原始：
 *           8
 *    	   /  \
 *    	  6   10
 *    	 / \  / \
 *    	5  7 9 11
 * 镜像：
 *           8
 *    	   /  \
 *    	  10   6
 *    	 / \  / \
 *    	11 9 7  5
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

void Mirror(TreeNode *pRoot) {
    if(!pRoot) return;
    TreeNode* left = pRoot->left;
    TreeNode* right = pRoot->right;
    if(!left && !right) return;
    pRoot->left = right;
    pRoot->right = left;
    Mirror(left);
    Mirror(right);
}

TreeNode* dfs(TreeNode *r){
    if(!r) return nullptr;
    TreeNode *lval = dfs(r->left);
    TreeNode *rval = dfs(r->right);
    r->left = rval;
    r->right = lval;
    return r;
}

void Mirror_(TreeNode *pRoot){
    if(!pRoot) return;
    dfs(pRoot);
}

//非递归 层次遍历
void bfs(TreeNode *root){
    queue<TreeNode*> pq;
    pq.push(root);
    while (!pq.empty())
    {
        int sz = pq.size();
        while(sz--){
            TreeNode *node = pq.front();pq.pop();
            //process node
            cout << node->val << " ";
            if(node->left) pq.push(node->left);
            if(node->right) pq.push(node->right);
        }
    }
}

//非递归版本
//从上往下交换
void Mirror__(TreeNode *pRoot){
    queue<TreeNode*> pq;
    pq.push(pRoot);
    while (!pq.empty())
    {
        int sz = pq.size();
        while (sz--)
        {
            TreeNode *node = pq.front();
            pq.pop();
            if(node->left) pq.push(node->left);
            if(node->right) pq.push(node->right);

            TreeNode *cur = node->left;
            node->left = node->right;
            node->right = cur;
        }
    }
}

int main(){
    TreeNode* pRoot = new TreeNode(8);
    pRoot->left = new TreeNode(6);
    pRoot->right = new TreeNode(10);
    pRoot->left->left = new TreeNode(5);
    pRoot->left->right = new TreeNode(7);
    pRoot->right->left = new TreeNode(9);
    pRoot->right->right = new TreeNode(11);
    Mirror(pRoot);
    return 1;
}