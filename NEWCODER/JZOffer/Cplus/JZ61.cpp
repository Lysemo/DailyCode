/**
 * 题目：
 *  请实现两个函数，分别用来序列化和反序列化二叉树
 * 二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
 * 从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，
 * 序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。
 * 
 * 二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
 * 
 * 例如，我们可以把一个只有根节点为1的二叉树序列化为"1,"，然后通过自己的函数来解析回这个二叉树 
 * 
 * 示例：
 * 输入：
 * {8,6,10,5,7,9,11}
 * 输出：
 * {8,6,10,5,7,9,11}
 */ 
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

char* Serialize(TreeNode *root) 
{
    if(root==nullptr)
    {
        //在返回地址时，函数里面的变量的地址是不能返回的，因为函数退出后，对应变量消失；
        //除非将其通过new处理，使内存在堆上
        return new char('\0');
    }
    string str;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty())
    {
        TreeNode* node = que.front();
        que.pop();
        if(node==nullptr)
        {
            str += "#";
            str += '!';
        }
        else
        {
            str += to_string(node->val);
            str += '!';
        }
        if(node!=nullptr)
        {
            que.push(node->left);
            que.push(node->right);
        }
    }
    char *tmp = new char[str.size()];
    strcpy(tmp,str.c_str());
    return tmp;
}
TreeNode* Deserialize(char *str) 
{
    string st = str;
    if(st.empty()) return nullptr;
    vector<string> vec;
    int i=0,j=0;
    while(i<st.size())
    {
        while(str[j]!='!' && j<st.size())
        {
            j++;
        }
        vec.push_back(st.substr(i,j-i));
        j++;
        i = j;
    }
    vector<TreeNode*> treeNodes;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]!="#")
        {
            treeNodes.push_back(new TreeNode(stoi(vec[i])));
        }
        else
        {
            treeNodes.push_back(nullptr);
        }
    }
    for(int i=0,j=1;j<treeNodes.size();i++)
    {
        if(treeNodes[i]!=nullptr)
        {
            treeNodes[i]->left = treeNodes[j++];
            treeNodes[i]->right = treeNodes[j++];
        }
    }
    return treeNodes[0];
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
    char* c = Serialize(n1);
    TreeNode* root = Deserialize(c); 
    return 0;
}