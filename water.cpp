#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
        // Your code here
        int dp[n+1];
        dp[0] = 0;
        for(int i=1;i<=n;i++ )
        {
            dp[i] = INT_MAX;
            for(int j=i-1;j>=0;j++)
            {
                if(arr[j] >= (i-j))
                {
                    if(dp[j]+1 < dp[i])
                    {
                        dp[i] = dp[j]+1;
                    }
                }
            }
            
        }
        return dp[n];
        
}
           
main()
{
	
	int n=12,m=8;
	int a1[]={1,4,3,2,7,6,8,11,15,5,6,4};
	int a2[]={1,4,3,2,7,6,11,9,25};
	cout<<minJumps(a1,n);
	
}
