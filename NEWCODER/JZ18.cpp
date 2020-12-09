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