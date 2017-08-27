#include<iostream>
#include<cstdio>
using namespace std;
char map[22][22];
int num;
int w,h;
void dfs(int x,int y);
int main()
{
	cin>>w>>h;
	while(!(w==0&&h==0))
	{
		num=0;
		for(int i=0;i<h;i++)
				scanf("%s",map[i]);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(map[i][j]=='@')
					dfs(i,j);
		printf("%d\n",num);
		cin>>w>>h;
	}
	return 0;
}
void dfs(int x,int y)
{
	map[x][y]='#';
	num++;
	if(x+1<h&&x+1>=0&&map[x+1][y]=='.')
		dfs(x+1,y);
	if(x-1<h&&x-1>=0&&map[x-1][y]=='.')
		dfs(x-1,y);
	if(y+1<w&&y+1>=0&&map[x][y+1]=='.')
		dfs(x,y+1);
	if(y-1<w&&y-1>=0&&map[x][y-1]=='.')
		dfs(x,y-1);
}
