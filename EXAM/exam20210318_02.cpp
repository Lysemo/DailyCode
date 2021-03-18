#include<iostream>

using namespace std;

int main(){
    int n;
    string wall;
    cin >> n >> wall;
    wall = " " + wall;
    int sum[n+1] = {0};
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1] + wall[i] - '0';
    }
    int ans = n;
    for(int i=0;i<=n;i++){
        ans = min(ans,i - sum[i] + sum[n] - sum[i]);
    }
    cout << ans;
    system("pause");
    return 0;
}