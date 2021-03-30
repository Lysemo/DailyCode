/**
 * 题目：
 * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
 * 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
 * 
 * 示例：
 * 输入：
 * {8,6,10,5,7,9,11}
 * 输出：
 * [[8],[10,6],[5,7,9,11]]
 */ 
#include<iostream>
#include<stack>
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

vector<vector<int> > Print(TreeNode* pRoot) {
    if(pRoot==nullptr)
    {
        return {};
    }
    vector<vector<int> > ret;
    stack<TreeNode*> tmp;
    queue<TreeNode*> que;
    que.push(pRoot);
    int level = 0;
    while(!que.empty())
    {
        int sz = que.size();
        level++;
        vector<int> *pv = new vector<int>;
        while(sz--)
        {
            TreeNode *node = que.front();
            que.pop();
            if((level%2)==0)
            {
                tmp.push(node);
            }
            else
            {
                pv->push_back(node->val);
            }
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        while(!tmp.empty())
        {
            pv->push_back(tmp.top()->val);
            tmp.pop();
        }
        ret.push_back(*pv);
        delete pv;
    }
    return ret;
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