#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    freopen("146 - ID Codes.txt", "r", stdin);
    string s;
    
    while(cin >> s, s!="#")
    {
        if(!next_permutation(s.begin(), s.end()))
        {
            cout << "No Successor" << endl;
        }
        
        else
        {
            cout << s << endl;
        }
    }
}