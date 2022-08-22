#include<bits/stdc++.h>
using namespace std;

void buildSegmentTree(int ind,int left,int right,int arr[],int seg[])
{
	if(left==right)
	{
		seg[ind]=arr[left];
		return;
	}
	int mid=(left+right)/2;
	buildSegmentTree(2*ind+1,left,mid,arr,seg);
	buildSegmentTree(2*ind+2,mid+1,right,arr,seg);
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
void update(int ind,int left,int right,int seg[],int i,int val)
{
	if(left==right)
	{
		seg[ind]=val;
		return;
	}
	int mid=(left+right)/2;
	if(i<=mid)
	  update(2*ind+1,left,mid,seg,i,val);
	else
	   update(2*ind+2,mid+1,right,seg,i,val);
	
	 seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	
}
void show(int seg[],int size)
{
	for(int j=0;j<size;j++)
	{
		cout<<seg[j]<<" ,";
	}
	cout<<endl;
	return;
}
int main()
{
	int n=16;
	int m=(2*n-1);
	int arr[n];
	int seg[m];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	buildSegmentTree(0,0,n-1,arr,seg);
	show(seg,m);
	update(0,0,m-1,seg,3,66);
	show(seg,m);
	update(0,0,m-1,seg,7,55);
	update(0,0,m-1,seg,13,75);
	update(0,0,m-1,seg,11,65);
	show(seg,m);
	
	return 0;
}
