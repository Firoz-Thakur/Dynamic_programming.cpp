knap_sack_problem.
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity 
of each item.In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an
integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot 
break an item, either pick the complete item, or don’t pick it (0-1 property).

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 int dp[1002][1002];
// memset(dp,-1,sizeof(dp));
int knapsack(int wt[],int val[],int w,int n,int dp[][1002])
 {
     if(n==0 ||w==0)
      return 0;
     
     if(dp[n][w]!=-1) 
        return dp[n][w];
     if(wt[n-1]<=w)
      {
          dp[n][w]=max((val[n-1]+knapsack(wt,val,w-wt[n-1],n-1,dp)),  knapsack(wt,val,w,n-1,dp));
      }    
     else
     {
         dp[n][w]=knapsack(wt,val,w,n-1,dp);
      
     }
   
   return dp[n][w];
 }
 
 
 int BU_knapsack(int wt[],int val[],int w,int n)
 {
    for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=w;j++)
         {
             if(i==0 || j==0)
               dp[i][j]==0; 
         } 
     }
     
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=w;j++)
         {
              if(wt[i-1]<=j)
              {
                  dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
              }
              else
               dp[i][j]=dp[i-1][j];
         }
     }
     return  dp[n][w];
 }

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   
       memset(dp,-1,sizeof(dp));
	    
	    int n,w;
	    cin>>n;
	    cin>>w;
	    int wt[n]={0};
	    int val[n]={0};
	    for(int i=0;i<n;i++)
	    {
	        cin>>val[i];
	    }
	    for(int i=0;i<n;i++)
	   {
	        cin>>wt[i];
	    }
	
	cout<<knapsack(wt,val,w,n,dp)<<endl;
	
	
//	cout<<BU_knapsack(wt,val,w,n)<<endl;
	}
	
	return 0;
}
