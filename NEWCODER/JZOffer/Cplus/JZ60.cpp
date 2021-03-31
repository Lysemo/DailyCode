/**
 * 题目：
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 * 
 * 示例：
 * 输入：
 * {8,6,10,5,7,9,11}
 * 输出：
 * [[8],[6,10],[5,7,9,11]]
 */ 
#include<iostream>
#include<vector>
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

vector<vector<int> > Print(TreeNode* pRoot) 
{
    if(pRoot==nullptr) return {};
    vector<vector<int>> res;
    queue<TreeNode*> que;
    que.push(pRoot);
    while(!que.empty())
    {
        int sz = que.size();
        vector<int> tmp;
        while(sz--)
        {
            TreeNode* node = que.front();
            que.pop();
            tmp.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        res.push_back(tmp);
    }
    return res;
}

int main()
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->right = n5;
    vector<vector<int>> ret = Print(n1);
    return 0;
}