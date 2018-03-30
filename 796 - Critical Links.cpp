#include <iostream>
#include <tr1/unordered_map>
#include <vector>

using namespace std;

int main()
{
  freopen("in.in", "r", stdin);

  int n;
  while(cin >> n, n)
  {
    string s;

    vector <vector <int> > adj(101);

    while(getline(cin, s))
    {
      int num = 0, x = 0, i, t;

      for(i = 0 ; i < s.length() ; i++)
      {
        if(s[i] == ' ')
        {
          x = num;
          break;
        }

        else
        {
          num = num * 10 + (s[i] - '0');
        }
      }

      for(int j = i + 2 ; j < s.length() ; j++)
      {
        if(s[j] == ')')
        {
          t = num;
          i = j + 2;
          break;
        }

        else
          num = num * 10 + (s[i] - '0');
      }

      for(int j = i ; j < s.length() ; j++)
      {
        if(s[j] == ' ')
        {
          adj[x].push_back(num);
          num = 0;
        }

        else
        {
          num = num * 10 + (s[i] - '0');
        }

        if(j == s.length() - 1)
        {
          num = num * 10 + (s[j] - '0');
          adj[x].push_back(num);
          adj[num].push_back(x);
        }
      }
    }

    for(int i = 1 ; i <= n ; i++)
    {
      cout << i << " ";
      for(int j = 0 ; j < adj[i].size() ; j++)
      {
        cout << adj[i][j] << " ";
      }

      cout << endl;
    }

  }
}
