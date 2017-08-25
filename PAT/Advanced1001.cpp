#include<iostream>
#include<string>
using namespace std;
int main()
{
	long a=0,b=0,x=1000;
	cin>>a>>b;
	long sum=a+b;
	int bitnum=1;
	long csum=sum;
	string outp;
	while(csum/10!=0)
	{
		bitnum++;
		csum=csum/10;
	}
	if(sum>=0)
	{
		int cm=0;
		while(sum/10!=0)
		{
			if(cm==3)
			{
				char temp=',';
				outp=temp+outp;
				cm=0;
			}
			else
			{
				char temp=sum%10+48;
				outp=temp+outp;
				sum=sum/10;
				cm++;
			}
		}
		if(cm==3)
		{
			char temp=',';
			outp=temp+outp;
			temp=sum+48;
			outp=temp+outp;
		}
		else
		{
			char temp=sum%10+48;
			outp=temp+outp;
		}
		
	}
	else
	{
		int cm=0;
		sum=-sum;
		while(sum/10!=0)
		{
			if(cm==3)
			{
				char temp=',';
				outp=temp+outp;
				cm=0;
			}
			else
			{
				char temp=sum%10+48;
				outp=temp+outp;
				sum=sum/10;
				cm++;
			}
		}
		if(cm==3)
		{
			char temp=',';
			outp=temp+outp;
			temp=sum+48;
			outp=temp+outp;
		}
		else
		{
			char temp=sum%10+48;
			outp=temp+outp;
		}
		char temp='-';
		outp=temp+outp;
	}
	cout<<outp;
	return 0;
	
}
