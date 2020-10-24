Given a String, find the longest palindromic subsequence

Input:
The first line of input contains an integer T, denoting no of test cases. The only line of each test case consists of a string S(only lowercase)

Output:
Print the Maximum length possible for palindromic subsequence.

Constraints:
1<=T<=100
1<=|Length of String|<=1000
 

Examples:
Input:
2
bbabcbcab
abbaab
Output:
7
4

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int n,int m)
{
  
  int dp[n+1][m+1];
  
  for(int i=0;i<=n;i++)
  {
      dp[i][0]=0;
  }
   
  for(int i=0;i<=m;i++)
  {
      dp[0][i]=0;
  }
  
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=m;j++)
      {
          if(s1[i-1]==s2[j-1])
          {
              dp[i][j]=1+dp[i-1][j-1];
          }
          else
          {
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
          
      }
  }
  
  
return dp[n][m];  
  
}


int main() {
	//code
	int t;
	cin>>t;
	cin.get();
	while(t--)
	{
	    string s1;
	    cin>>s1;
	    string s2;
	    for(int i=s1.size()-1;i>=0;i--)
	    {
	        s2.push_back(s1[i]);
	    }
	    
	    cout<<lcs(s1,s2,s1.size(),s1.size())<<endl;
	    
	  
	}
	
	
	return 0;
}
