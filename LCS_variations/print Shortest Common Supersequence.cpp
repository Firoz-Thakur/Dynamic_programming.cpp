Question is same as the LCS print:
https://leetcode.com/problems/shortest-common-supersequence/


Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)


Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

  
 
 
 
 
 
 
 
 
 
 
 string shortestCommonSupersequence(string s1, string s2) {
    
        int n=s1.size();
        int m=s2.size();
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
   int i=s1.size();
   int j=s2.size();
    string s3;   
   while(i>0 && j>0)
   {
       if(s1[i-1]==s2[j-1])
       {
          s3.push_back(s2[j-1]); 
           i--;
           j--;
       }
       else if(dp[i-1][j]>dp[i][j-1])
       {
           s3.push_back(s1[i-1]);
           i--;
       }
       else
       {
            s3.push_back(s2[j-1]);
            j--;
       }
   }
        
        while(i>0)
        {
            s3.push_back(s1[i-1]);
            i--;
        }
        while(j>0)
        {
            s3.push_back(s2[j-1]);
            j--;
        }
        reverse(s3.begin(),s3.end());
        
       return s3;
        
    }
