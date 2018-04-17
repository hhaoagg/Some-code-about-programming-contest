#include <iostream>
using namespace std;
int data[1000000];
void solve(int x)
{
	if(x == 1 || x == 2)
		return ;
	for(int i = 3; i <= x; i++)
	{
		long long c = 0;
		if(i % 2 != 0)
			c = data[i - 1];
		else
		{
			c += data[i - 1];
			c += data[i / 2];
		}
		data[i] = (int)(c % 1000000000);
	}	
};
int main()
{
	data[1] = 1;
	data[2] = 2;
	int n = 0;
	cin >> n;
	
	solve(n);
	cout << data[n] << endl;
	return 0;	
 } 
