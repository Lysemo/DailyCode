/**
 * 题目：
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 * 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 
 * a b c e 
 * s f c s 
 * a d e e
 * 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
 * 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
 * 
 * 示例：
 * 输入：
 * "ABCESFCSADEE",3,4,"ABCCED"
 * 输出：
 * true
 * 
 * 输入：
 * "ABCESFCSADEE",3,4,"ABCB"
 * 输出：
 * false
 */ 
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class Solution {
public:    
    bool judge(const char* matrixs,const char* strs,bool* visited,int rows,int cols,int i,int j,int k,int sz)
    {
        int is_visited_pos = i*cols+j;
        if(i<0 || i>=rows || j<0 || j>=cols || visited[is_visited_pos]==true ||matrixs[is_visited_pos]!=strs[k])
        {
            return false;
        }
        if(k==sz-1)
        {
            return true;
        }
        visited[is_visited_pos] = true;
        if(judge(matrixs, strs, visited, rows, cols, i-1, j, k+1, sz) ||
            judge(matrixs, strs, visited, rows, cols, i+1, j, k+1, sz) ||
            judge(matrixs, strs, visited, rows, cols, i, j-1, k+1, sz) ||
            judge(matrixs, strs, visited, rows, cols, i, j+1, k+1, sz)
            )
        {
            return true;
        }
        visited[is_visited_pos] = false;
        return false;
    }
    bool hasPath(string matrix, int rows, int cols, string str) {
        // write code here
        bool visited[rows*cols];
        memset(visited, false, sizeof(visited));
        const char *matrixs = matrix.c_str();
        const char* strs = str.c_str();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(judge(matrixs,strs,visited,rows,cols,i,j,0,str.size()))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s1;
    string matrix = "ABCESFCSADEE";
    string str = "ABCCED";
    cout << s1.hasPath(matrix,3,4,str) << endl;
    system("pause");
    return 0;
}