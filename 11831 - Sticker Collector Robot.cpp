#include <iostream>

using namespace std;

int main()
{
    freopen("in.in", "r", stdin);
    
    int n, m, q;
    
    while(cin >> n >> m >> q, n || m || q)
    {
        int x, y, ans = 0;
        char dir;
        
        string s[n];
        
        for(int i = 0 ; i < n ; i++)
        {
            cin >> s[i];
            
            for(int j = 0 ; j < m ; j++)
            {
                if(s[i][j] == 'N' || s[i][j] == 'S' || s[i][j] == 'L' || s[i][j] == 'O')
                {
                    x = i, y = j;
                    dir = s[i][j];
                    
                    if(dir == 'L')
                    {
                        dir = 'E';
                    }
                    
                    else if(dir == 'O')
                    {
                        dir = 'W';
                    }
                }
            }
        }
        
        string ins;
        cin >> ins;
        
        for(int i = 0 ; i < q ; i++)
        {
            if(ins[i] == 'F')
            {
                if(dir == 'N' && x != 0)
                {
                    if(s[x - 1][y] != '#')
                    x--;
                }
                
                if(dir == 'S' && x != n - 1)
                {
                    if(s[x + 1][y] != '#')
                    x++;
                }
                
                if(dir == 'W' && y != 0)
                {
                    if(s[x][y - 1] != '#')
                    y--;
                }
                
                if(dir == 'E' && y != m - 1)
                {
                    if(s[x][y + 1] != '#')
                    y++;
                }
            }
            
            else if(ins[i] == 'D')
            {
                if(dir == 'N')
                    dir = 'E';
                
                
                else if(dir == 'S')
                    dir = 'W';
                
                
                else if(dir == 'E')
                    dir = 'S';
                
                
                else if(dir == 'W')
                    dir = 'N';
            }
            
            else
            {
                if(dir == 'N')
                    dir = 'W';
                
                
                else if(dir == 'S')
                    dir = 'E';
                
                
                else if(dir == 'E')
                    dir = 'N';
                
                
                else if(dir == 'W')
                    dir = 'S';
            }
            
            if(s[x][y] == '*')
            {
                ans++;
                s[x][y] = '.';
            }
            
            //cout << x << " " << y << endl;
            
        }
        
        cout << ans << endl;
    }
}