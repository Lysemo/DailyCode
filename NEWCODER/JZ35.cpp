#include<iostream>
#include<vector>

using namespace std;

int InversePairs(vector<int> data) {
    if(data.empty()) return 0;
    int cnt = 0;
    for(int i=0;i<data.size()-1;i++){
        for(int j=i+1;j<data.size();j++){
            if(data[i]>data[j]) cnt++;
        }
    }
    if(cnt<1000000007) return cnt;
    return (cnt-1000000007);
}

int main(){
    vector<int> data = {1,2,3,4,5,6,7,0};
    cout << InversePairs(data) << endl;
    system("pause");
    return 1;
}