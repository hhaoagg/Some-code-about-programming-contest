#include<iostream>
using namespace std;
void dfs(int x,int y);
char map[101][101];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>map[i][j];
	int res=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(map[i][j]=='W')
			{
				dfs(i,j);
				res++;
			}
	cout<<res;
	return 0;
}
void dfs(int x,int y)
{
	map[x][y]='.';
	int ax=0,ay=0;
	for(ax=-1;ax<=1;ax++)
		for(ay=-1;ay<=1;ay++)
			if(x+ax>=0&&x+ax<n&&y+ay>=0&&y+ay<m&&map[x+ax][y+ay]=='W')
				dfs(x+ax,y+ay);
	return ;
}
