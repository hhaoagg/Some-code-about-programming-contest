\*这里需要一个定理做支撑
世界上任意六个人中,一定有三个人互相认识,或三个人互相不认识
这就是著名的六度分隔理论。*\

#include<iostream>
using namespace std;
int par[3001],ranks[3001];
bool map[3002][3002];
void init(int n)
{
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		ranks[i]=0;
	}
}
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return ;
	if(ranks[x]<ranks[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(ranks[x]==ranks[y]) ranks[x]++;
	}
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
bool judgerela(int x,int y);
int main()
{
	int t;
	cin>>t;
	while(t--!=0)
	{
		int n;
		cin>>n;			
		init(n);
		bool judge=true;
		for(int i=0;i<n-1;i++)
			for(int j=0;j<n-1-i;j++)
			{
				int temp=0;
				cin>>temp;
				if(temp==1)
				{
					if(!same(i,i+j+1))
						unite(i,i+j+1);
					map[i][j]=true;
				}
				else
					map[i][j]=false;
			}
		if(n>=6)
		{
			cout<<"Bad Team!"<<endl;
			continue;
		}
		int sum=0;
		for(int i=0;i<n-1;i++)
		{
			bool pand=true;
			for(int j=0;j<i+1;j++)
				if(same(j,1+i))
					pand=false;
			if(pand)
				sum++;
		}
		if(sum>=3)
			judge=false;
		for(int i=0;i<n-1;i++)
		{
			int record[3001];
			int renum=0;
			for(int j=0;j<n-1-i;j++)
				if(map[i][j])
				{
					record[renum]=j;
					renum++;
				}
			for(int i=0;i<renum-1;i++)
				for(int j=0;j<renum-1-i;j++)
					if(!judgerela(record[j]+i+1,record[j+1]-record[j]))
						judge=false;
		}
		if(judge)
			cout<<"Great Team!"<<endl;
		else
			cout<<"Bad Team!"<<endl;
	}
	return 0;
}
bool judgerela(int x,int y)
{
	return !map[x][y-1];
}
