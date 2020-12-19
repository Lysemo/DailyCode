/**
 * 
 * 题目：
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
 * 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
 * 则打印出这三个数字能排成的最小数字为321323
 * 
 * 示例：
 * 输入：
 * [3,32,321]
 * 输出：
 * "321323"
 * 
 * 要求：
 * 时间限制：C/C++ 1秒，其他语言2秒
 * 空间限制：C/C++ 64M，其他语言128M
 */ 

#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 比较两个字符串s1, s2大小的时候，先将它们拼接起来，
// 比较s1+s2,和s2+s1那个大，如果s1+s2大，那说明s2应该放前面，
// 所以按这个规则，s2就应该排在s1前面

string PrintMinNumber(vector<int> numbers) {
    string res = "";
    if(numbers.empty()) return res;
    vector<string> part;
    int ll = 0;
    for(int i=0;i<numbers.size();i++){
        string s = to_string(numbers[i]);
        part.push_back(s);
        ll = s.size()>ll?s.size():ll;
    }
    for(int i=0;i<part.size();i++){
        int t = ll-part[i].size();
        char lastC = part[i][part[i].size()-1];
        while (t--)
        {
            part[i] += lastC;
        }
    }
    vector<int> index(part.size(),0);
    for(int i=0;i<part.size();i++){
        for(int j=0;j<part.size();j++){
            if(part[i].compare(part[j])>0){
                index[i]++;
            }
        }
    }
    int n = 0;
    while (n<part.size())
    {
        for(int i=0;i<part.size();i++){
            if(index[i]==n){
                res += to_string(numbers[i]);
            }
        }
        n++;
    }
    return res;     
}

string PrintMinNumber_(vector<int> numbers){
    string res = "";
    if(numbers.empty()) return res;
    for(int i=0;i<numbers.size();i++){
        for(int j=i+1;j<numbers.size();j++){
            string s1 = to_string(numbers[i])+to_string(numbers[j]);
            string s2 = to_string(numbers[j])+to_string(numbers[i]);
            if(s1.compare(s2)>0){
                swap(numbers[i],numbers[j]);
            }
        }
    }
    for(int i=0;i<numbers.size();i++)
        res += to_string(numbers[i]);
    return res;
}

int main(){
    vector<int> numbers = {3,32,321};
    cout << PrintMinNumber(numbers) << endl;
    cout << PrintMinNumber_(numbers) << endl;
    system("pause");
    return 1;
}