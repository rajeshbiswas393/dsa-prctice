/*

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays


Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int dp[m+1][n+1];
        int ans=0;
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                 dp[i][j]=0;
                if(i==0 || j==0)
                   continue;
                else
                {
                    if(nums1[i-1]==nums2[j-1])
                    {
                        dp[i][j]=1+dp[i-1][j-1];
                        ans=max(dp[i][j],ans);
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
            }
        }
        return ans;
    }
};
