#include<iostream>
#include<stack>

using namespace std;

int main()
{
    freopen("514 - Rails.txt", "r", stdin);
    freopen("514 - Rails.out", "w", stdout);
    
    int n;
    
    while(cin >> n, n != 0)
    {
        while(1)
        {
            stack <int> stk, st1, st2, st;

            for(int i = n ; i >= 1 ; i--)
            {
                stk.push(i);
            }
            
            for(int i = 0 ; i < n ; i++)
            {
                int x;
                cin >> x;
                
                if(x == 0)
                {
                    cout << endl;
                    goto label;
                }
                
                st.push(x);
            }
            
            while(!st.empty())
            {
                st1.push(st.top());
                st.pop();
            }
            
            while(!st2.empty() || !stk.empty())
            {
                if(st1.empty())
                {
                    break;    
                }
                
                else if(st2.empty())
                {
                    if(!stk.empty())
                    {
                        st2.push(stk.top());
                        stk.pop();
                    }
                    
                    else
                    {
                        break;
                    }
                }
                
                else if(st2.top() == st1.top())
                {
                    st1.pop();
                    st2.pop();
                }
                
                else if(st2.top() != st1.top())
                {
                    if(!stk.empty())
                    {
                        st2.push(stk.top());
                        stk.pop();
                    }
                    
                    else
                    {
                        break;
                    }

                }
            }
            
            if(st1.empty())
            {
                cout << "Yes" << endl;
            }
            
            else
            {
                cout << "No" << endl;
            }
        }
        
        label:;
    }
}
