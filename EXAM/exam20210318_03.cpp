#include<iostream>

using namespace std;

int main(){
    int count1[256]={0},count2[256]={0},count3[256]={0};
    int s1=0,s2=0,s3=0;
    int n;
    string str1,str2,str3;
    cin >> n >> str1 >> str2 >> str3;
    int size = str1.length();
    for(int i=0;i<size;i++){
        s1 = max(s1,++count1[str1[i]]);
        s2 = max(s2,++count2[str2[i]]);
        s3 = max(s3,++count3[str3[i]]);
    }
    if(s1==size && n==1) s1--; else s1 = min(s1+n,size);
    if(s2==size && n==1) s1--; else s2 = min(s2+n,size);
    if(s3==size && n==1) s1--; else s3 = min(s3+n,size);
    if(s1>s2 && s1>s3)
        cout << "xiaoming";
    else if(s2>s1 && s2>s3)
        cout << "xiaowang";
    else if(s2>s1 && s2>s3)
        cout << "xiaoli";
    else
        cout << "draw";
    system("pause");
    return 0;
}