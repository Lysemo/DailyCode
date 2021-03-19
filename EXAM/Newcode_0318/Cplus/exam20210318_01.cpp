#include<iostream>
#include<vector>

using namespace std;


long long findMaxButtons(vector<int> buttons){
    long long ans = buttons.size();
    for(int i=0;i<buttons.size();i++){
        ans += (long long)(buttons[i]-1)*(i+1);
    }
    return ans;
}

int main(){
    vector<int> buttons = {2,2,2};
    long long ret = findMaxButtons(buttons);
    cout << ret << endl;
    system("pause");
    return 0;
}