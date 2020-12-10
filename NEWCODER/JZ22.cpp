/**
 * 
 * 题目：
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 * 
 * 示例：
 * 输入：
 * {5,4,#,3,#,2,#,1}
 * 输出：
 * [5,4,3,2,1]
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
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

vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> arr;
    if(!root) return arr;
    queue<TreeNode*> pd;
    pd.push(root);
    while(!pd.empty()){
        int sz = pd.size();
        while(sz--){
            TreeNode *node = pd.front();
            pd.pop();
            arr.push_back(node->val);
            if(node->left) pd.push(node->left);
            if(node->right) pd.push(node->right);
        }
    }
    return arr;
}

vector<int> PrintFromTopToBottom_(TreeNode* root) {
    vector<int> arr;
    if(!root) return arr;
    queue<TreeNode*> pd;
    pd.push(root);
    while(!pd.empty()){
        TreeNode *node = pd.front();
        pd.pop();
        arr.push_back(node->val);
        if(node->left) pd.push(node->left);
        if(node->right) pd.push(node->right);
    }
    return arr;
}

int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->left->left = new TreeNode(1);
    vector<int> arr = PrintFromTopToBottom(root);
    // vector<int> arr = PrintFromTopToBottom_(root);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << " " << endl;
    system("pause");
    return 1;
}