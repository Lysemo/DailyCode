/**
 * 
 * 题目：
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 * 
 * 示例：
 * 输入：
 * [[1,2],[3,4]]
 * 输出：
 * [1,2,4,3]
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>

using namespace std;

void printArr(vector<vector<int>> matrix,int left,int right,int top,int bottom,vector<int> &arr){
    if(left>right || top>bottom) return;
    if(left==right){
        for(int i=top;i<=bottom;i++){
            arr.push_back(matrix[i][left]);
        }
        return;
    }
    if(top==bottom){
        for(int j=left;j<=right;j++){
            arr.push_back(matrix[top][j]);
        }
        return;
    }
    for(int j=left;j<=right;j++){
        arr.push_back(matrix[top][j]);
    }
    for(int i=top+1;i<=bottom-1;i++){
        arr.push_back(matrix[i][right]);
    }
    for(int j=right;j>=left;j--){
        arr.push_back(matrix[bottom][j]);
    }
    for(int i=bottom-1;i>=top+1;i--){
        arr.push_back(matrix[i][left]);
    }
    left++;top++;right--;bottom--;
    printArr(matrix,left,right,top,bottom,arr);
}

//3ms | 376k
vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> arr;
    printArr(matrix,0,matrix[0].size()-1,0,matrix.size()-1,arr);
    return arr;
}

int main(){
    vector<vector<int> > matrix(4,vector<int>(4));
    int b[4][4] = {{1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matrix[i][j] = b[i][j];
        }
    }
    vector<int> arr = printMatrix(matrix);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    system("pause");
    return 1;
}