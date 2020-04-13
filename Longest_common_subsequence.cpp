#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lcs(string a,string b)
{ 
 int m=a.size();
 int n=b.size();
 int dp[100][100];
 for(int i=0;i<100;i++)
  dp[i][0]=0;
 for(int j=0;j<100;j++)
  dp[0][j]=0;
 for(int i=1;i<=m;i++)
  {
  	for(int j=1;j<=n;j++)
  	{
  		int q=0;
  		if(a[i-1]==b[j-1])
  		   q=1+dp[i-1][j-1];
  		else
  		   q=max(dp[i-1][j],dp[i][j-1]);
  	
  	    dp[i][j]=q;
  	}
  }
 return dp[m][n];  
}
int main() {
	// your code goes here
	string s;
	string s2;
	cin>>s>>s2;
	cout<<lcs(s,s2);
	return 0;
}
