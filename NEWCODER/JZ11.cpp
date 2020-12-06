#include<iostream>
#include<vector>

using namespace std;

//时间占用4ms | 内存占用360k
int  NumberOf1(int n) {
        vector<int> num(32,0);
        int c = -n;
        int index = 0;
        if(n==-2147483648){
            return 1;
        }
        if(n<0){
            num[num.size()-1] = 1;
            c = n*(-1);
        }
        while(c!=0){
            num[index] = c%2;
            c = c/2;
            index ++;
        }
        if(n<0){
            num[0] = num[0] ^ 1;
            num[0] = num[0] + 1;
            int flg = num[0]/2;
            num[0] = num[0]%2;
            for(int i=1;i<num.size()-1;i++){
                num[i] = num[i] ^ 1;
                num[i] = num[i] + flg;
                flg = num[i]/2;
                num[i] = num[i]%2;
            }
        }
        int count = 0;
        for(int i=0;i<num.size();i++)
            count = count + (num[i] ^ 0);
        return count;
    }

int main(){
    int n = -2147483648;
    cout << NumberOf1(-2147483648) << endl;
    system("pause");
    return 1;
}