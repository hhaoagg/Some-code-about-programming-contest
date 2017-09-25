#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 1000100
int data[maxn];
int main()
{
	int t=0;
	cin>>t;
	while(t--!=0)
	{
		int l,n;
		scanf("%d%d",&l,&n);
		for(int i=0;i<n;i++)
			scanf("%d",&data[i]);
		int max=0,min=0;
		for(int i=0;i<n;i++)
		{
			if((l-data[i])>data[i])
			{
				if(data[i]>max)
					max=data[i];
			}
			else
			{
				if(l-data[i]>max)
					max=l-data[i];
			}
			if((l-data[i])>data[i])
			{
				if((l-data[i])>min)
					min=l-data[i];
			}
			else
			{
				if(data[i]>min)
					min=data[i];
			}
		}
		printf("%d %d\n",max,min);
	}
	return 0;
}
