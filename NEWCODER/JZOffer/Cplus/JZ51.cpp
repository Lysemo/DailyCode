/**
 * 题目：
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
 * 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
 * 不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
 * 对于A长度为1的情况，B无意义，故而无法构建，因此该情况不会存在。 
 * 
 * 示例：
 * 输入：
 * [1,2,3,4,5]
 * 输出：
 * [120,60,40,30,24]
 * 
 */ 
#include<iostream>
#include<vector>

using namespace std;

vector<int> multiply(const vector<int>& A) 
{
    if(A.empty())
    {
        return {};
    }
    vector<int> B(A.size(),1) ;
    for(int i=0;i<B.size();++i)
    {
        for(int j=0;j<B.size();j++)
        {
            if(i!=j)
            {
                B[i] = B[i]*A[j];
            }
        }
    }
    return B;
}

vector<int> multiply_(const vector<int>& A) 
{
    if(A.empty())
    {
        return {};
    }
    vector<int> B(A.size(),1) ;     //记录前i项累乘
    vector<int> C(A.size(),1) ;     //记录后i项累乘
    vector<int> D(A.size(),1) ;
    int preB = 1, postC = 1;
    for(int i=0;i<A.size();++i)
    {
        B[i] = preB*A[i];
        C[A.size()-1-i] = postC*A[A.size()-1-i];
        preB = B[i];
        postC = C[A.size()-1-i];
    }
    D[0] = C[1];
    D[D.size()-1] = B[B.size()-2];
    for(int i=1;i<D.size()-1;i++)
    {
        D[i] = B[i-1]*C[i+1];   //D[i] = 前i-1项累乘 * 后size-i-1项累乘
    }
    return D;
}

int main()
{
    vector<int> D1 = multiply({1,2,3,4,5});
    vector<int> D2 = multiply({1,2,3,4,5});
    for(int v:D1)
    {
        cout << v << " ";
    }
    cout << endl;
    for(int v:D2)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}