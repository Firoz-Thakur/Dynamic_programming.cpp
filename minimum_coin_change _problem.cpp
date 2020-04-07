//given coin find the minimum coin to make its change


//top down dp---->>>>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fin_min_change(int n,int dp[],int coin[],int t)
{  
    if(n==0)
     return 0;
    if(dp[n]!=0)
     return dp[n];
    int ans=INT_MAX;
    for(int i=0;i<t;i++)
    { 
    	if(n-coin[i]>=0){
    	int sub=fin_min_change(n-coin[i],dp,coin,t);
    	ans=min(ans,sub+1);
    }
 }
  dp[n]=ans;
  return dp[n];
}

int main() {
	// your code goes here
	int n;
//	cin>>n;
    n=7;
    int dp[100]={0};
    int coins[]={1,3,5};
    int t=3;
	cout<<fin_min_change(n,dp,coins,t);
	return 0;
}



//using bottom up dp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fin_min_change(int n,int dp[],int coin[],int t)
{  
 if(n==0)
  return 0;
 	
 for(int i=1;i<=n;i++)
 {
  int ans=INT_MAX;	
  for(int j=0;j<t;j++)
  {
  	int sub;
  	if(i-coin[j]>=0)
  	{
      sub=dp[i-coin[j]]+1;
      ans=min(ans,sub);
   	}
  }
 dp[i]=ans;
 }
 return dp[n];
}

int main() {
	// your code goes here
	int n;
//	cin>>n;
    n=7;
    int dp[100]={0};
    int coins[]={1,3,5};
    int t=3;
	cout<<fin_min_change(n,dp,coins,t);
	return 0;
}
