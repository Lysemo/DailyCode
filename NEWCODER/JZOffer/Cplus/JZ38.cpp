/**
 * 
 * 题目：
 * 输入一棵二叉树，求该树的深度。从根结点到叶结点
 * 依次经过的结点（含根、叶结点）形成树的一条路径，
 * 最长路径的长度为树的深度
 * 
 * 示例：
 * 输入：
 * {1,2,3,4,5,#,6,#,#,7}
 * 输出：
 * 4
 */ 

#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

//非递归层次遍历 运用queue先进先出的性质
int TreeDepth(TreeNode* pRoot) {
    int ret = 0;
    if(pRoot==nullptr) return ret;
    queue<TreeNode *> que;
    que.push(pRoot);
    while(que.size()!=0){
        int size = que.size();
        ret ++;
        while(size--){
            TreeNode *node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    return ret;
}


int TreeDepth_(TreeNode *pRoot)
{
    if(!pRoot) return 0;
    int lval = TreeDepth_(pRoot->left);
    int rval = TreeDepth_(pRoot->right);
    return max(lval,rval)+1;
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(5);
    int d1 = TreeDepth(root);
    int d2 = TreeDepth_(root);
    cout << d1 << " | " << d2 << endl;
    system("pause");
    return 0;
}