#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
    int a,b,c;
    int ans;
	int t1,t2;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		t1=abs(a-1);
		t2=abs(b-c)+abs(c-1);
		if(t1<t2)
		ans=1;
		else if(t2<t1)
		ans=2;
		else
		ans=3;
		cout<<ans<<endl;
	}
	return 0;
}
