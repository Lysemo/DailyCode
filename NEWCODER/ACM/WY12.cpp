#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s,t;
    while (cin>>s>>t)
    {
        if(t.size()==0)
        {
            cout << "Yes" << endl;
            return 0;
        }
        if(s.size()==0)
        {
            cout << "No" << endl;
            return 0;
        } 
        int ti = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[ti])
            {
                ti++;
                if(ti>=t.size())
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        cout << "No" << endl;
    }
    return 0;
}