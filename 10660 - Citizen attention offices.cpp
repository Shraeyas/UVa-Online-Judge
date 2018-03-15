#include <iostream>
#include <tr1/unordered_map>

using namespace std;

int main()
{
    freopen("10660 - Citizen attention offices.txt", "r", stdin);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        tr1 :: unordered_map <int, int> pop;
        
        int n;
        cin >> n;
        
        for(int i = 0 ; i < n ; i++)
        {
            int x, y;
            cin >> x >> y;
            
            cin >> pop[x * 5 + y];
        }
        
        for(int i = 0 ; i < 25 ; i++)
        {
            if(pop[i] > 0)
            {
                int min_dis = 999999;
                
                min_dis = min (min_dis, pop[i]);
            }
        }
    }
}