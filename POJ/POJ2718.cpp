/*
注意组合两个数时不能有先导0
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int	dat[15];
int num = 0, ans = 999999;
void solve()
{
	ans = 999999;
	int mid = 0;
	if(num % 2 == 0)
		mid = num / 2 - 1;
	else
		mid = num / 2;
	
	do
	{
		int x = 0, y = 0;	
		if(dat[0] != 0 && dat[mid + 1] != 0)
		{
			for(int i = 0; i < mid + 1; i++)
				x = x * 10 + dat[i];
			for(int i = mid + 1; i < num; i++)
				y = y * 10 + dat[i];
			if(x > y)
				x = x - y;
			else
				x = y - x;
			if(x < ans)
				ans = x;
		}
	}
	while(next_permutation(dat, dat + num));
	
	cout << ans << endl;
	
}
int main()
{
	int t = 0;
	cin >> t;
	getchar();
	while(t-- != 0)
	{
		num = 0;
		char inp = '1';
		while((inp = getchar()) != '\n')
		{
			if(inp != ' ')
			{
				dat[num] = inp - 48;
				num++;
			}
		}
		if(num == 1)
			cout << dat[0] << endl;
		else if(num == 2)
			cout << abs(dat[0] - dat[1]) << endl;
		else
			solve();
		
	}
	return 0;
 } 
