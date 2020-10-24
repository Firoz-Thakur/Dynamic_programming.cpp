https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions/0#

Given a string 'str' of size ‘n’. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.

Note: The order of characters should be maintained.

 

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the 
length of string str.

The second line of each test case contains the string str.


Output:

Print the minimum number of characters to be deleted to make the string a palindrome for each testcase in a new line.


Constraints:

1<= T <=100

1<= N <= 1000


Example:

Input:

1

7

aebcbda

Output:

2












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
	    int n;
	    cin>>n;
	    string s1;
	    cin>>s1;
	    string s2;
	    for(int i=s1.size()-1;i>=0;i--)
	    {
	        s2.push_back(s1[i]);
	    }
	    
	  cout<<s1.size()-lcs(s1,s2,s1.size(),s1.size())<<endl;
	  
	    
	  
	}
	
	
	return 0;
}
