#include<bits/stdc++.h>
using namespace std;

long long countCobmination(long long  num)
{
	long long currentNumber=num;
	int count=0,digit;
	int currCount=0;
	long long current;
	long long ans;
	while(currentNumber>1)
	{
		count++;
		currentNumber/=10;
	}
	long long coff=pow(10,count-1);
	currCount = count;
	int ind=0;
	while(coff>0)
	{
		current=(num/coff);
		digit=(current%10);
		coff/=10;
		if(digit>=1)
		{
			if(ind==0)
			  ans+=(digit-1)*pow(10,currCount-1);
			else
			  ans+=digit*pow(10,currCount-1);
		}
		ind++;
		currCount--;
		cout<<digit<<endl;
	}
	
	return ans;
}

int main()
{
	long long num;
	long long ans;
	while(1)
	{
		cout<<"Enter the number:"<<endl;
		cin>> num;
		ans=countCobmination(num);
		cout<<"Number Count="<<ans<<endl;
	}
}
