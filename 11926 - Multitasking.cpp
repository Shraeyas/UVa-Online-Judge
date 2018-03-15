#include <iostream>
#include <tr1/unordered_map>

using namespace std;

tr1::unordered_map<int, int>check;

int mark(int x, int y)
{
    for(int i = x ; i < y ; i++)
    {
        //cout<<i <<" "<<check[i]<<endl;
        if(check[i] == 1)
        {
            return 1;
        }
        
        check[i] = 1;
    }
    
    //check[x] = 1;
    
    return 0;
}


int mark_rep(int x, int y, int rep)
{
    int s = 0, chk = 0;
    
    while(s <= 1000000)
    {
        chk = mark(x+s, min(y+s, 1000000));
        
        if(chk == 1)
            return 1;
        
        s += rep;
    }
    
    return 0;
}

int main()
{
    freopen("11926 - Multitasking.txt", "r", stdin);
    
    int n, m;
    
    while(cin >> n >> m, n || m)
    {
        check.clear();
        
        int chk = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            int x, y;
            cin >> x >> y;
            
            if(chk != 1)
            chk = mark(x, y);
        }
        
        for(int i = 0 ; i < m ; i++)
        {
            int x, y, rep;
            
            cin >> x >> y >> rep;
            
            if(chk != 1)
            chk = mark_rep(x, y, rep);
        }
        
        if(chk == 1)
        {
            cout<<"CONFLICT"<<endl;
        }
        
        else
        {
            cout<<"NO CONFLICT"<<endl;
        }
    }
}