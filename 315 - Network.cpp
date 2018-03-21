#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

vector <vector <int> > adj(101);
tr1 :: unordered_map <int, int> vis;
int critical = 0;

void dfs(int s, int off)
{
	vis[s] = 1;

	for(int i = 0 ; i < adj[s].size() ; i++)
	{
		if((adj[s][i] != off) && (!vis[adj[s][i]]))
		{
			dfs(adj[s][i], off);
		}
	}
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int n;

	while(cin >> n, n)
	{
		critical = 0;

		vis.clear();


		for(int i = 0 ; i < 101 ; i++)
		{
			adj[i].clear();
		}

		string s;

		int l = 0;

		while(getline(cin, s))
		{
			vector <int> input;

			if(s == "0")
			break;

			int num = 0;

			for(int i = 0 ; i < s.length() ; i++)
			{
				if((s[i] == ' '))
				{
					input.push_back(num);
					num = 0;
				}

				else
				{
					num = num * 10 + (s[i] - '0');
				}

				if(i == s.length() - 1)
				{
					input.push_back(num);
				}
			}

			for(int i = 1 ; i < input.size() ; i++)
			{
				adj[input[0]].push_back(input[i]);
				adj[input[i]].push_back(input[0]);
			}
			//cout << endl;
		}

		/*for (int i = 1 ; i <= n ; i++)
		{
			for (int j = 0 ; j < adj[i].size() ; j++)
			cout << adj[i][j] << " ";
			cout << endl;
		}*/

		for(int i = 1 ; i <= n ; i++)
		{
			vis.clear();

			if(i == 1)
				dfs(2, i);

			else
				dfs(1, i);

			for(int j = 1 ; j <= n ; j++)
			{
				if(j != i && !vis[j])
				{
 					critical++;
					goto label;
				}
			}

			label:;
		}

		cout << critical << endl;
	}
}
