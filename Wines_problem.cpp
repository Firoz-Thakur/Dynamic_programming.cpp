wines problem :
In one year you can only sell one of the wine from extreme end,and after every year profit become =wine[i]* y mean after every year wines
price is geting increasing.
//top down dp

#include <bits/stdc++.h>
using namespace std;

int find_profit(int i,int j,int dp[][100],int wines[],int y)
{
   if(i>j)
    return 0;
   if(dp[i][j]!=0) 
    return dp[i][j];
   
   int option1=wines[i]*y + find_profit(i+1,j,dp,wines,y+1);
   int option2=wines[j]*y + find_profit(i,j-1,dp,wines,y+1);
   int ans=max(option1,option2);
   dp[i][j]=ans;
   return dp[i][j];
}


int main()
{
	int dp[100][100]={0};
	int wine[]={2,3,5,1,4};
	int i=0;
	int j=4;
	int y=1;
	cout<<find_profit(i,j,dp,wine,y);
}
