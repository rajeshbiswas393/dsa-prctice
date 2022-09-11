#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> a,b;
	for(int i=1;i<=100;i++)
	{
		a.push_back(i);
	}
	while(a.size()>1)
	{
		b.clear();
		for(int j=1;j<=a.size();j++)
		{
			//cout<<j<<", ";
			if((j%2)!=0)
			{
				b.push_back(a[j-1]);
				cout<<a[j-1]<<", ";
				
			}
			
			 
		}
		a=b;
		cout<<a.size()<<endl;
	}
	cout<<a[0];
	return 0;
}
