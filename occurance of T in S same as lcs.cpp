Given two strings S and T of length n and m respectively. find count of distinct occurrences of T in S as a sub-sequence. 
 

Example 1:

Input:
S = "banana" , T = "ban"
Output: 3
Explanation: There are 3 sub-sequences:
[ban], [ba n], [b an].

â€‹Example 2:

Input:
S = "geeksforgeeks" , T = "ge"
Output: 6
Explanation: There are 6 sub-sequences:
[ge], [ ge], [g e], [g e] [g e] and [ g e].

 

Your Task:
You don't need to read input or print anything.Your task is to complete the function subsequenceCount() which takes two strings as argument S and T and returns the 
count of the sub-sequences modulo 109 + 9.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<=length of(T)<=100
1<=length of(S)<=8000















/*You are required to complete this method*/

//int dp[8001][1001];
/*
int help(string s,string t,int n,int m)
{
    if(n==0)
     return 0;
    if(m==0)
     return 1;
     
   if(dp[n][m]!=-1)
    return dp[n][m]%1000000007;
    if(s[n-1]==t[m-1])
      dp[n][m]=(help(s,t,n-1,m)%1000000007+help(s,t,n-1,m-1)%1000000007)%1000000007;
    else
      dp[n][m]=help(s,t,n-1,m)%1000000007;
    
    return dp[n][m]%1000000007;
}
*/

int subsequenceCount(string S, string T)
{
  
  //Your code here
  int n=S.size();
  int m=T.size();
  
//  memset(dp,-1,sizeof(dp));
  //return help(S,T,n,m);
  int dp[n+1][m+1];
  
  for(int i=0;i<=m;i++)
  {
      dp[0][i]=0;
  }
  for(int i=0;i<=n;i++)
  {
      dp[i][0]=1;
  }
  
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=m;j++)
      {
          if(S[i-1]==T[j-1])
          {
              dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%1000000007;
          }
          else
          {
             dp[i][j]=dp[i-1][j]%1000000007;
          }
      }
  }
  return dp[n][m];
  
}
 
