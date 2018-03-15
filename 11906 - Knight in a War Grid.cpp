#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

int r, c, m, n, pra[2][8], even, odd;
tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > done, water;

bool xrange(int x)
{
	if(x < r && x >= 0)
	return 1;
	
	return 0;
}

bool yrange(int x)
{
	if(x < c && x >= 0)
	return 1;
	
	return 0;
}

void dfs(int x, int y)
{
	tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > vis;
	
	int total = 0;
	done[x][y] = 1;
	
	for(int i = 0 ; i < 8 ; i++)
	{	
		int a = x + pra[0][i], b = y + pra[1][i];
		
		if(!vis[a][b] && xrange(a) && yrange(b) && !water[a][b])
		{
			total++;
		
			if(!done[a][b])
			{
				dfs(a, b);
			}
			
			vis[a][b] = 1;
		}
	}
	
	if(total % 2 == 0)
	{
		even++;
	}
	
	else
	{
		odd++;
	}	
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t, cs = 1;
	cin >> t;
	
	while(t--)
	{
		done.clear();
		water.clear();
		even = 0, odd = 0;
		
		cin >> r >> c >> m >> n;
		
		pra[0][0] =  m, pra[1][0] =  n;
		pra[0][1] = -m, pra[1][1] =  n;
		pra[0][2] =  m, pra[1][2] = -n;
		pra[0][3] = -m, pra[1][3] = -n;
		pra[0][4] =  n, pra[1][4] =  m;
		pra[0][5] = -n, pra[1][5] =  m;
		pra[0][6] =  n, pra[1][6] = -m;
		pra[0][7] = -n, pra[1][7] = -m;
		
		int w;
		cin >> w;
		
		for(int i = 0 ; i < w ; i++)
		{
			int x, y;
			
			cin >> x >> y;
			water[x][y] = 1;
		}
		
		dfs(0, 0);
		
		cout << "Case " << cs++ << ": " << even << " " << odd << endl;
	}
}
