#include<bits/stdc++.h>
using namespace std;

set<int> ans;

void generateNumbs(int coff,int num,int k,int prev)
{
	int currentNum;
	if(coff==1)
	{
		currentNum= (prev+num);
		ans.insert(currentNum);
		cout<<currentNum<<endl;
		return;
	}
	
	currentNum=prev+(num*coff);
	
	if((num-k)>=0)
	{
		generateNumbs(coff/10,num-k,k,currentNum);
	}
	if((num+k)<=9)
	{
		generateNumbs(coff/10,num+k,k,currentNum);
	}
	
	return;
}

int main()
{
	int n,k;
	while(1)
	{
		cout<<"Enter value of n ans k"<<endl;
		cin>>n>>k;
		int coff=pow(10,n-1);
		ans.clear();
		for(int i=1;i<=9;i++)
		{
			if(k<=9)
			{
				generateNumbs(coff,i,k,0);
			}
		}
		
	    cout<<"Total numbers="<<ans.size()<<endl;
	}
	
	
	return 0;
}
