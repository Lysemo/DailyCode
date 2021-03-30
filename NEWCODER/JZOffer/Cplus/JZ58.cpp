/**
 * 题目：
 * 请实现一个函数，用来判断一棵二叉树是不是对称的。
 * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 * 
 * 示例：
 * 输入：
 * {8,6,6,5,7,7,5}
 * 输出：
 * true
 * 
 * 输入：
 * {8,6,9,5,7,7,5}
 * 输出：
 * false
 * 
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

bool check(TreeNode* node1,TreeNode* node2)
{
    if(node1==nullptr && node2==nullptr)
    {
        return true;
    }
    if(node1==nullptr || node2==nullptr)
    {
        return false;
    }
    if(node1->val!=node2->val)
    {
        return false;
    }
    return check(node1->left, node2->right) && check(node1->right,node2->left);
}

bool isSymmetrical(TreeNode* pRoot) {
    if(pRoot==nullptr)
    {
        return true;
    }
    TreeNode* left = pRoot->left;
    TreeNode* right = pRoot->right;
    return check(left,right);
}

int main()
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(2);
    TreeNode *n4 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(3);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->right = n5;
    cout << isSymmetrical(n1) << endl;
    system("pause");
    return 0;
}