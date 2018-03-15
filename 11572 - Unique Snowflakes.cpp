#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    freopen("11572 - Unique Snowflakes.txt", "r", stdin);
    freopen("11572 - Unique Snowflakes.out", "w", stdout);
    long t;
    cin >> t;
    
    while(t--)
    {
        
        long n, ans = 0, c = 0;
        cin >> n;
        
        map <long, long> m, lastpos;
        
        for(long i = 0 ; i < n ; i++)
        {
            long x;
            cin >> x;
            
            if(m[x] == 1)
            {
                ans = max(ans, i - lastpos[x]);
                
                lastpos[x] = i;
                c = ans;
            }
            
            else
            {
                c++;
                m[x] = 1;
                lastpos[x] = i;
                c++;
                ans = max(ans, c);
            }
        }
        
        cout << ans << endl;
    }
}