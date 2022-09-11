#include<bits/stdc++.h>
using namespace std;

set<int> ans;
void generateNum(int coff,int digit,int prev)
{
	//cout<<prev<<endl;
	if(coff==1) {
		int num=(prev+digit);
		ans.insert(num);
		cout<<num<<endl;
		return;
	}
	for(int i=0;i<=digit;i++)
	{
		int nextPrev=prev+(coff*digit);
		int nextCoff(coff/10);
		generateNum(nextCoff,i,nextPrev);
	}
	return;
}
int main()
{
	int n;
	while(1)
	{
			ans.clear();
			cin>>n;
			int coff=pow(10,n-1);
			//cout<<coff<<endl;
			for(int i=1;i<=9;i++)
			{
				generateNum(coff,i,0);
			}
			cout<<"The Number count:"<<ans.size()<<endl;
	}

	return 0;
}
