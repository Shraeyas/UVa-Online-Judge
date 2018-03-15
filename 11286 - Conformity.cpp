#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("11286 - Conformity.txt", "r", stdin);
    
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;

    while(cin >> n, n)
    {        
        if(n == 0)
            break;
        
        int ans = 0, x = 0;
        map <string, int> m;
        
        for(int i = 0 ; i < n ; i++)
        {
            vector <string> v(5);
            string s;
            
            for(int j = 0 ; j < 5 ; j++)
            {
                cin >> v[j];
            }
            
            sort(v.begin(), v.end());
            
            for(int j = 0 ; j < 5 ; j++)
            {
                s += v[j];
            }
            
            m[s]++;
            
            ans = max(ans, m[s]);
            
        }
        
        for(map<string, int> :: iterator it = m.begin() ; it != m.end() ; it++)
        {
            if(it->second == ans)
                x += ans;
        }
        
        printf("%d\n", x);
    }
}