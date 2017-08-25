#include<iostream>
#include<iomanip>
using namespace std;
int main()
{	
	float data[1009]={0.0};
	int m=0,max=0;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int n=0;
		float a=0.0;
		cin>>n>>a;
		if(n>max) max=n;
		data[n]=data[n]+a;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int n=0;
		float a=0.0;
		cin>>n>>a;
		if(n>max) max=n;
		data[n]=data[n]+a;
	}
	int num=0;
	for(int i=0;i<=max;i++)
		if(data[i]!=0)
			num++;
	cout<<num;
	for(int i=0;i<=max;i++)
		if(data[max-i]!=0)
			cout<<" "<<max-i<<" "<<setprecision(1)<<std::fixed<<data[max-i];
	return 0;
}
