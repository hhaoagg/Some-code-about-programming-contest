#include<iostream>
#include<string>
using namespace std;
int main()
{
	string unlocker,locker;
	string ultime="99:99:99";
	string ltime="00:00:00";
	int m=0;
	cin>>m;
	while(m--!=0)
	{
		string a,b,c;
		cin>>a>>b>>c;
		if(b<ultime)
		{
			ultime=b;
			unlocker=a;
		}
		if(c>ltime)
		{
			ltime=c;
			locker=a;
		}
	}
	cout<<unlocker<<" "<<locker;
	return 0;
}
