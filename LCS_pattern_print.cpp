vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {

 int n1=a.size();
 int n2=b.size();
 int dp[n1+1][n2+1];
 for(int i=0;i<=n1;i++)
 {
     dp[i][0]=0;
 }
 for(int i=0;i<=n2;i++)
 {
     dp[0][i]=0;
 }

  for(int i=1;i<=n1;i++)
  {
      for(int j=1;j<=n2;j++)
      {
         if(a[i-1]==b[j-1])
         {
             dp[i][j]=1+dp[i-1][j-1];
         }
        else
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
      }
  }
 int i=n1;
 int j=n2;
 vector<int> v;
  while(i>0 && j>0)
  {
   if(a[i-1]==b[j-1])
   {
       v.push_back(a[i-1]);
       i--;
       j--;
   }
   else if(dp[i][j-1]>dp[i-1][j])
   {
       j--;
   }
   else
   {
       i--;
   }
  }

 reverse(v.begin(),v.end());
 return v;
}
