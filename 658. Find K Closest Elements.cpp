class Compare
{
public:
    bool operator() (pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first==b.first)
        {
            return (a.second>b.second);
        }
        return (a.first>b.first);
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int> ,vector<pair<int,int>>,Compare> pq;
        int s=arr.size();
        for(int i=0;i<s;i++)
        {
            int diff=abs(arr[i]-x);
            pq.push({diff,arr[i]});
        }
        int n=0;
        vector<int> ans;
        while(n<k)
        {
            pair<int,int> curr=pq.top();
            ans.push_back(curr.second);
            pq.pop();
            n++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
