Unbounded Knapsack (Repetition of items allowed)
Last Updated: 22-04-2020
Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate minimum amount that could make up this quantity exactly.
This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.

Examples:

Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
There are many ways to fill knapsack.
1) 2 instances of 50 unit weight item.
2) 100 instances of 1 unit weight item.
3) 1 instance of 50 unit weight item and 50
   instances of 1 unit weight items.
We get maximum value with option 2.

Input : W = 8
       val[] = {10, 40, 50, 70}
       wt[]  = {1, 3, 4, 5}       
Output : 110 
We get maximum value with one unit of
weight 5 and one unit of weight 3.







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
          dp[n][w]=max((val[n-1]+knapsack(wt,val,w-wt[n-1],n,dp)),  knapsack(wt,val,w,n-1,dp));
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
                  dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
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
