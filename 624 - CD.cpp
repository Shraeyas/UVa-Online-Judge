#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, s;
vector <int> num;

struct node
{
    vector <int> v;
    int sum = 0;
};

node solve(int i, node ob)
{
    if(i == num.size())
    {
        return ob;
    }
    
    
    node x = solve(i + 1, ob);    
    node y = solve(i + 1, (node) {ob.v.push_back(num[i]), ob.sum + num[i]});
    
    if(x.sum == y.sum)
    {
        if(x.v.size() > y.v.size())
            return x;
        
        return y;
    }
    
    else if(x.sum > y.sum && x.sum < s)
    {
        return x;
    }
    
    else
    {
        return y;
    }
}

int main()
{    
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    freopen("in.in", "r", stdin);
    
    while(cin >> s)
    {
        num.clear();
        
        cin >> n;
        
        for(int i = 0 ; i < n ; i++)
        {
            int x;
            cin >> x;
            
            num.push_back(x);
        }
        
        int m = 99999, total = 0;
        vector <int> p;
        
        node x = solve(0, (node){p, 0});
        
        for(int i = 0 ; i < x.v.size() ; i++)
        {
            cout << x.v[i] << " ";
        }
        
        cout << "sum:" << x.sum << endl;
        
        
    }
}