#include <iostream>
#include <map>

using namespace std;

bool nbr(int i, int j)
{
    i = i^j;
    
    return (i & (-i)) == i;
}

int main()
{
    freopen("10264 - The Most Potent Corner.txt", "r", stdin);
    
    int n;
    
    while(cin >> n)
    {
        map<int, int>f;
        int x;
        
        for(int i = 0 ; i < (1<<n) ; i++)
        {
            cin >> x;
            
            for(int j = 0 ; j< (1<<n) ; j++)
            {
                if(nbr(i, j) && i != j)
                {
                    f[j] += x;
                }
            }
        }
        
        int maxi = -1;
        
        for(int i = 0 ; i< (1<<n) ; i++)
        {
            for(int j = 0 ; j< (1<<n) ; j++)
            {
                if(!(!nbr(i, j) || i == j))
                {
                    maxi = max(f[i] + f[j], maxi);
                }
            }
        }
        
        cout << maxi << endl;
    }
}