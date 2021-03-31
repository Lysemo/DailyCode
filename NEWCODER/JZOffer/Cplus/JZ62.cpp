/**
 * 题目：
 * 给定一棵二叉搜索树，请找出其中的第k小的TreeNode结点。
 * 
 * 示例：
 * 输入：
 * {5,3,7,2,4,6,8},3
 * 输出：
 * {4}
 * 说明：按结点数值大小顺序第三小结点的值为4  
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


int i = 1;
TreeNode* inOrder(TreeNode* node,int k)
{
    if(node==nullptr || k<=0)
    {
        return nullptr;
    }
    TreeNode* left = inOrder(node->left, k);
    if(left!=nullptr)
    {
        return left;
    }
    if(i++==k)    //当前节点为第几个访问的节点
    {
        return node;
    }
    return inOrder(node->right, k);
}
TreeNode* KthNode(TreeNode* pRoot, int k) 
{
    return inOrder(pRoot, k);
}

int main()
{
    TreeNode *n1 = new TreeNode(6);
    TreeNode *n2 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(8);
    TreeNode *n4 = new TreeNode(2);
    TreeNode *n5 = new TreeNode(10);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->right = n5;
    TreeNode* p = KthNode(n1,4);
    return 0;
}