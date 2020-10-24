Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. 
It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1:

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.












int lcs(string &s1,string &s2,int i,int j,int dp[1001][1001])
    {
     if(i==s1.length()|| j==s2.length())
    {
        return 0;
    }
  if(dp[i][j]!=-1)
   {
       return dp[i][j];
   }
  if(s1[i]==s2[j])
  {
      dp[i][j]=1 + lcs(s1,s2,i+1,j+1,dp);
  }
  else 
  {
     dp[i][j]=max(lcs(s1,s2,i,j+1,dp),lcs(s1,s2,i+1,j,dp));
  }
  return dp[i][j];
}




	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n1=str1.size();
	    int n2=str2.size();
	    int dp[1001][1001];
	    
	    for(int i=0;i<n1;i++)
	    {
	        for(int j=0;j<n2;j++)
	        {
	            dp[i][j]=-1;
	        }
	    }
	   
	   int len=lcs(str1,str2,0,0,dp);
	 // cout<<len<<endl;
	    int d=n1-len;
	    int ini=n2-len;
	    return (d+ini);
	} 
