#include <iostream>

using namespace std;

bool iszero(int arr[3][3])
{
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			if(arr[i][j] != 0)
			{
				return 0;
			}
		}
	}
	
	return 1;
}

int main()
{
	//freopen("in.in", "r", stdin);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		
		int ar[3][3], ans = 0, arr[3][3];
		
		ar[0][0] = s1[0] - '0';
		ar[0][1] = s1[1] - '0';
		ar[0][2] = s1[2] - '0';
		
		ar[1][0] = s2[0] - '0';
		ar[1][1] = s2[1] - '0';
		ar[1][2] = s2[2] - '0';
		
		ar[2][0] = s3[0] - '0';
		ar[2][1] = s3[1] - '0';
		ar[2][2] = s3[2] - '0';
		
		/*for(int i = 0 ; i < 3 ; i++)
			{
				for(int j = 0 ; j < 3 ; j++)
				{
					cout << ar[i][j];
				}
				
				cout << endl;
			}
			cout << endl;*/
		
		while(1)
		{
			if(iszero(ar))
			{
				cout << ans - 1 << endl;
				break;
			}
			
			arr[0][0] = (ar[1][0] + ar[0][1]) % 2;
			arr[0][1] = (ar[0][0] + ar[1][1] + ar[0][2]) % 2;
			
			//cout << endl << endl << ar[0][0] << " " << ar[1][1] << " " << ar[0][2] << endl << endl;
			
			arr[0][2] = (ar[0][1] + ar[1][2]) % 2;
			
			arr[1][0] = (ar[0][0] + ar[1][1] + ar[2][0]) % 2;
			arr[1][1] = (ar[0][1] + ar[2][1] + ar[1][0] + ar[1][2]) % 2;
			arr[1][2] = (ar[0][2] + ar[2][2] + ar[1][1]) % 2;
			
			arr[2][0] = (ar[1][0] + ar[2][1]) % 2;
			arr[2][1] = (ar[2][0] + ar[2][2] + ar[1][1]) % 2;
			arr[2][2] = (ar[2][1] + ar[1][2]) % 2;
			
			
			
			ans++;
			
			for(int i = 0 ; i < 3 ; i++) 
			{
				for(int j = 0 ; j < 3 ; j++)
				{
					ar[i][j] = arr[i][j];
				}
			}
		}
	}
}
