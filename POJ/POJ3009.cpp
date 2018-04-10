#include <iostream>
using namespace std;
int w = 0, h = 0;
int map[25][25];
int ans = 0;
void dfs(int l, int x, int y)
{
	if(l < 11)
	{
		if(map[x][y] == 3)
		{
			if(l < ans)
				ans = l;
		}
		else
		{
			
			if((x - 1) >= 0 && map[x - 1][y] != 1)
			{
				int temp = 0;
				while((x - 1 - temp) >= 0 && map[x - 1 - temp][y] != 1 && map[x - temp][y] != 3)
					temp++;
				if(map[x - temp][y] == 3)
					dfs(l + 1, x - temp, y);
				else if((x - temp) != 0)
				{
					map[x - 1 - temp][y] = 0;
					dfs(l + 1, x - temp, y);
					map[x - 1 - temp][y] = 1;
				}
			}
			
			if((y - 1) >= 0 && map[x][y - 1] != 1)
			{
				int temp = 0;
				while((y - 1 - temp) >= 0 && map[x][y - 1 - temp] != 1 && map[x][y - temp] != 3)
					temp++;
				if(map[x][y - temp] == 3)
					dfs(l + 1, x, y - temp);
				else if((y - temp) != 0)
				{
					map[x][y - 1 - temp] = 0;
					dfs(l + 1, x, y - temp);
					map[x][y - 1 - temp] = 1;
				}
			}
			
			if((y + 1) <= w - 1 && map[x][y + 1] != 1)
			{
				int temp = 0;
				while((y + 1 + temp) <= w - 1 && map[x][y + 1 + temp] != 1 && map[x][y + temp] != 3)
					temp++;
				if(map[x][y + temp] == 3)
					dfs(l + 1, x, y + temp);
				else if((y + temp) != w - 1)
				{
					map[x][y + 1 + temp] = 0;
					dfs(l + 1, x, y + temp);
					map[x][y + 1 + temp] = 1;
				}
			}
			
			if((x + 1) <= h - 1 && map[x + 1][y] != 1)
			{
				int temp = 0;
				while((x + 1 + temp) <= h - 1 && map[x + 1 + temp][y] != 1 && map[x + temp][y] != 3)
					temp++;
				if(map[x + temp][y] == 3)
					dfs(l + 1, x + temp, y);
				else if((x + temp) != h - 1)
				{
					map[x + 1 + temp][y] = 0;
					dfs(l + 1, x + temp, y);
					map[x + 1 + temp][y] = 1;
				}
			}
		}
	}
}
int main()
{
	cin >> w >> h;
	while(!(w == 0 && h == 0))
	{
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				cin >> map[i][j];
		
		ans = 50;
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				if(map[i][j] == 2)
					dfs(0, i, j);
		if(ans == 50)
			cout << -1 << endl;
		else
			cout << ans << endl;
		cin >> w >> h;
	}
	return 0;
 } 
