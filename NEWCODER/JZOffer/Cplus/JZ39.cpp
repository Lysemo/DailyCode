/**
 * 
 * 题目：
 *  输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 * 在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
 * 平衡二叉树（Balanced Binary Tree），具有以下性质：
 * 它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。
 * 
 * 示例：
 * 输入：
 * {1,2,3,4,5,6,7}
 * 输出：
 * true
 * 
 */ 

#include<iostream>
#include<map>

using namespace std;

struct TreeNode
{
    TreeNode(int v):
        left(nullptr),
        right(nullptr),
        value(v)
    {}
    TreeNode *left;
    TreeNode *right;
    int value;
};

map<TreeNode*,int> hs;
int depth(TreeNode* root){
    if(!root) return 0;
    if(hs.find(root)!=hs.end()) return hs[root];
    int ldep = depth(root->left);
    int rdep = depth(root->right);
    return hs[root] = max(ldep,rdep)+1;
}
bool judge(TreeNode* root){
    if(!root) return true;
    return abs(hs[root->left]-hs[root->right])<=1 && 
        judge(root->left) && judge(root->right);
}
bool IsBalanced_Solution(TreeNode* pRoot) {
    depth(pRoot);
    return judge(pRoot);
}

int depth_(TreeNode* root){
    if(!root) return 0;
    int ldep = depth(root->left);
    if(ldep == -1) return -1;
    int rdep = depth(root->right);
    if(rdep == -1) return -1;
    int sub = abs(ldep-rdep);
    if(sub>1) return -1;
    return max(ldep,rdep)+1;
}
bool IsBalanced_Solution_(TreeNode* pRoot) {
    return depth_(pRoot) != -1;
}

int main()
{
    TreeNode *pRoot = new TreeNode(1);
    pRoot->left = new TreeNode(2);
    pRoot->right = new TreeNode(3);
    pRoot->left->left = new TreeNode(4);
    bool ib1 = IsBalanced_Solution(pRoot);
    bool ib2 = IsBalanced_Solution_(pRoot);
    cout << ib1 << endl;
    cout << ib2 << endl;
    system("pause");
    return 0;
}