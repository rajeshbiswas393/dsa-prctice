/*

Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.



*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct comp {
    bool operator()(const vector<int>& x, const vector<int>& y) {
        return x[0]==y[0] ? x[1]<y[1] : x[0]>y[0];
    }
};
vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                pq.push({i+j,i,j});
            }
        }
        while(!pq.empty())
        {
            vector<int> vt=pq.top();
            ans.push_back(nums[vt[1]][vt[2]]);
            pq.pop();
        }
    return ans;
    }
};
