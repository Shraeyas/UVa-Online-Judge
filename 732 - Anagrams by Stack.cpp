#include <iostream>

using namespace std;

void calc(string a, string b, string c, string d, string op)
{
    if(d == b)
    {
        cout << op.substr(0, op.length() - 1) << endl;
        return;
    }
    
    if(d.length() != 0)
    {
        if(d[d.length() - 1] != b[d.length() - 1])
            return;
    }
    
    if(a.length() != 0)
    {
        calc(a.substr(1, a.length()), b, c + a[0], d, op + "i ");
    }
    
    if(c.length() != 0)
    {        
        calc(a, b, c.substr(0, c.length() - 1), d + c[c.length() - 1], op + "o ");
    }
}

int main()
{
    freopen("732 - Anagrams by Stack.txt", "r", stdin);
    freopen("732 - Anagrams by Stack.out", "w", stdout);
    
    string a, b;
    
    while(cin >> a >> b)
    {
        cout << "[" << endl;
        
        if(a.length() == b.length())
        calc(a, b, "", "", "");
        
        cout << "]" << endl;
    }
}