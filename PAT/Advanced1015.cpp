#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int trans(int x,int d);
int judgepm(int x);
int main()
{
	int n=0,d=0;
	cin>>n;
	while(n>0)
	{
		cin>>d;
		if(judgepm(n)==0)
			cout<<"No"<<endl;
		else
		{
			if(judgepm(trans(n,d))==1)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		cin>>n;
	}
	return 0;
}
int judgepm(int x)
{
	if(x==1) return 0;
  for(int i=2;i<=sqrt(x);i++)
    if(x%i==0)
      return 0;
  return 1;
}
int trans(int x,int d)
{
	string a,b;
	while(x>=d)
	{
		a=(char)(x%d)+a;
		x=x/d;
	}
	a=(char)(x)+a;
	for(int i=0;i<a.length();i++)
		b=a[i]+b;
	int level=1;
	x=0;
	for(int i=0;i<b.length();i++)
	{
		x+=b[b.length()-1-i]*level;
		level*=d;
	}
	return x;
}
