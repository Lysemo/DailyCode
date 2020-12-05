#include<iostream>
#include<vector>

using namespace std;

//时间占用2ms | 空间占用480k
int jumpFloorII(int number) {
    vector<int> dp(number+1,0);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=number;i++){
        for(int j=0;j<i;j++){
            dp[i] = dp[i] + dp[j];
        }
    }
    return dp[number];
}

////时间占用3ms | 空间占用356k
int jumpFloorII_(int number) {
    if(number==0 || number==1) return 1;
    int pre = 1,res;
    for(int i=2;i<=number;i++){
        res = pre << 1;
        pre = res;
    }
    return res;
}

//时间占用3ms | 空间占用352k
int jumpFloorII__(int number) {
    if(number==0 || number==1) return 1;
    return 1 << (number-1);
}

int main(){
    cout<<jumpFloorII(3) <<endl;
    cout<<jumpFloorII_(3) <<endl;
    cout<<jumpFloorII__(3) <<endl;
    system("pause");
    return 1;
}