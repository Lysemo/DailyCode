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

int main(){
    cout<<jumpFloorII(3) <<endl;
    system("pause");
    return 1;
}