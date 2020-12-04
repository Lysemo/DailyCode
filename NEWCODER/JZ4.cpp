#include<vector>
#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* rebuild(vector<int>& pre,int pre_left,int pre_right,vector<int>& vin,int vin_left,int vin_right){
    if(pre_left>pre_right) return nullptr;
    TreeNode* root = new TreeNode(pre[pre_left]);
    for(int i=vin_left;i<=vin_right;i++){
        if(vin[i]==root->val){
            root->left = rebuild(pre,pre_left+1,pre_left+i-vin_left,vin,vin_left,i-1);
            root->right = rebuild(pre,pre_left+i-vin_left+1,pre_right,vin,i+1,vin_right);
            break;
        }
    }
    return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin){
    return rebuild(pre,0,pre.size()-1,vin,0,vin.size()-1);
}

int main(){
    int a[] = {1,2,3,4,5,6,7};
    vector<int> pre(a,a+7);
    int b[] = {3,2,4,1,6,5,7};
    vector<int> vin(b,b+7);
    TreeNode* root = reConstructBinaryTree(pre,vin);
    return 1;
}