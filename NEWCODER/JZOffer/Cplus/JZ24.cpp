/**
 * 
 * 题目：
 * 输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 * 
 * 示例：
 * 输入：
 * {10,5,12,4,7},22
 * 输出：
 * [[10,5,7],[10,12]]
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

class Solution {
public:
    using vvi = vector<vector<int>>;
    using vi = vector<int>;
    void dfs(TreeNode *root,int sum,vi &path, vvi &ret){
        path.push_back(root->val);
        if(sum==root->val && !root->left && !root->right){
            ret.push_back(path);
        }
        if(root->left) dfs(root->left,sum-root->val,path,ret);
        if(root->right) dfs(root->right,sum-root->val,path,ret);
        path.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vvi ret;
        vi path;
        if(!root) return ret;
        dfs(root,expectNumber,path,ret);
        return ret;
    }
};

int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    Solution s;
    vector<vector<int>> ret = s.FindPath(root,22);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[0].size();j++){
            cout << ret[i][j] << "->";
        }
        cout << " " << endl;
    }
    system("pause");
    return 1;
}