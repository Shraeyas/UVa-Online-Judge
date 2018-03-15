#include <tr1/unordered_map>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    tr1 :: unordered_map <int, int> var;
    
    vector <int> hash;
    
    for(int i = 1 ; i <= 20 ; i++)
    {
        for(int j = 1 ; j <= 3 ; j++)
        {
            if(var[i * j] == 0)
            hash.push_back(i * j);
            
            var[i * j] = 1;
        }
    }
    
    hash.push_back(0);
    hash.push_back(50);
    
    while(cin >> n, n > 0)
    {
        int ans = 0;
        
        for(int i= 0 ;  i < hash.size() ; i++)
        {
            for(int j = 0 ; j < hash.size() ; j++)
            {
                for(int  k = 0 ; k < hash.size() ; k++)
                {
                    if(hash[i] + hash[j] + hash[k] == n)
                        ans++;
                }
            }
        }
        
        cout << ans << endl;
    }
}