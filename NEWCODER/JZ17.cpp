/**
 * 
 * 题目：
 * 输入两棵二叉树A，B，判断B是不是A的子结构。
 * （ps：我们约定空树不是任意一个树的子结构）
 * 
 * 示例：
 * 输入：
 * {8,8,#,9,#,2,#,5},{8,9,#,2}
 * 输出：
 * true
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

bool dfs(TreeNode *r1, TreeNode *r2) {
    if (!r2) return true;
    if (!r1) return false;
    return r1->val==r2->val && dfs(r1->left, r2->left) && dfs(r1->right, r2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
    if (!pRoot1 || !pRoot2) return false;
    return dfs(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}
int main(){
    TreeNode* pRoot1 = new TreeNode(8);
    pRoot1->left = new TreeNode(8);
    pRoot1->left->left = new TreeNode(9);
    pRoot1->left->left->left = new TreeNode(2);
    pRoot1->left->left->left->left = new TreeNode(5);

    TreeNode* pRoot2 = new TreeNode(8);
    pRoot2->left = new TreeNode(9);
    pRoot2->left->left = new TreeNode(2);

    cout << HasSubtree(pRoot1,pRoot2) << endl;
    system("pause");
    return 1;
}