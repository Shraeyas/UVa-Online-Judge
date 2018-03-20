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

	for(int i = 0 ; i < adj.size() ; i++)
	{
		if(adj[s][i] != off && !vis[adj[s][i]])
			dfs(adj[s][i], off);
	}
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int n;

	while(cin >> n)
	{
		critical = 0;

		vis.clear();
		adj.clear();

		string s;

		int l = 0;

		while(getline(cin, s), s != "0")
		{
			for(int i = 2 ; i < s.length() ; i += 2)
			{
				adj[s[0] - '0'].push_back(s[i] - '0');
				adj[s[i] - '0'].push_back(s[0] - '0');
			}
		}

		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i + 1 ; j <= n ; j++)
			{
				if (j == i)
					continue;

					vis.clear();

				dfs(i, j);

				for(int j = 1 ; j <= n ; j++)
				{
					if(j != i && !vis[j])
						critical++;
						break;
				}
			}
		}

		cout << critical << endl;

	}

}
