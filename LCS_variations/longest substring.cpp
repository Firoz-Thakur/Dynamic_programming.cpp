Longest Common Substring 
Medium Accuracy: 35.96% Submissions: 57687 Points: 4
Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

Example:
Testcase 1: CDGH is the longest substring present in both of the strings.
 

Company Tag





#include <bits/stdc++.h>
#include <iostream>
using namespace std;



int l_sub_string(string s1,string s2,int n,int m)
{
  
  int dp[n+1][m+1];
   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=m;j++)
       {
           if(i==0 || j==0)
            dp[i][j]=0;
       }
   }
   int mx=-1;
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
              dp[i][j]=0;
          }
       }
   }
       
     for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=m;j++)
       {
           
         mx=max(dp[i][j],mx);
       }
   }   
      
 return mx;
}
int main() {
	//code
	int t;
	cin>>t;
	//c.get();
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cin.get();
        string s1,s2;
        cin>>s1>>s2;
       // memset(dp,-1,sizeof(dp));
        cout<<l_sub_string(s1,s2,s1.size(),s2.size())<<endl;
        
    }
	
	return 0;
}






