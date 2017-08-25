#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string toeng(int x);
int main()
{
	char inp[103];
	int sum=0;
	cin>>inp;
	for(int i=0;i<strlen(inp);i++)
		sum+=inp[i]-48;
	if(sum>99)
		cout<<toeng(sum/100)<<' '<<toeng((sum%100)/10)<<' '<<toeng(sum%10);
	if(sum<100&&sum>9)
		cout<<toeng(sum/10)<<' '<<toeng(sum%10);
	if(sum<10)
		cout<<toeng(sum);
	return 0;
}
string toeng(int x)
{
	if(x==0) return "zero";
	if(x==1) return "one";
	if(x==2) return "two";
	if(x==3) return "three";
	if(x==4) return "four";
	if(x==5) return "five";
	if(x==6) return "six";
	if(x==7) return "seven";
	if(x==8) return "eight";
	if(x==9) return "nine";
}
