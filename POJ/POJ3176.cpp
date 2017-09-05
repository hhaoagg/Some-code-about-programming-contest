#include<iostream>
using namespace std;
int main()
{
	int n=0;
	int dp[360][360];
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<i+1;j++)
			cin>>dp[i][j];
	for(int i=1;i<n;i++)
		for(int j=0;j<i+1;j++)
		{
			if(j==0)
				dp[i][j]+=dp[i-1][j];
			else if(j==i)
					dp[i][j]+=dp[i-1][j-1];
			     else
			    	dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
		}
	int re=0;
	for(int i=0;i<n;i++)
		if(dp[n-1][i]>re)
			re=	dp[n-1][i];
	cout<<re;
	return 0;
}
