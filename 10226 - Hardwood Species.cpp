#include <iostream>
#include <map>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{
    freopen ("10226 - Hardwood Species.txt", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    getchar();
    getchar();
    
    while(t--)
    {
        map <string, int> freq;
        string s;
        int n = 0;
        
        while(getline(cin, s))
        {
            if(s.compare("") == 0)
            {
                break;
            }
            
            freq [s]++;
            n++;
        }
        
        for(map <string, int> :: iterator it = freq.begin() ; it != freq.end() ; it++)
        {
            cout << it -> first << " " << fixed << setprecision(4) << it->second*100.0/n << endl;
        }
        
        if(t)
            cout << endl;
    }
}