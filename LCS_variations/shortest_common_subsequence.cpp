Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.

NOTE : it is mendatory that string in the final string must be same means(continues) order should be same of s1 and s2 in between we can induce other letter as well(sequence)

uthan->chaiye> nahaana> pdna

this can also be modified as >
uthan> phone chalana >chaiye>dhup jalan>nahana>pdna

the order of s1 is same but the other letter are just add extra ,and the other letter would be the letter of the s2


Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two space-separated strings.

Output:
For each testcase, in a new line, output the length of the required string.


Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
Explanation:
Test Case 1: One of the shortest answer can be abxycd, which is of length 6.









#include <iostream>
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
	//code\
	
 int t;
 cin>>t;
 cin.get();
 while(t--)
 {
     string s1;
     string s2;
     cin>>s1;
     cin>>s2;
     int n=s1.size();
     int m=s2.size();a
     int l=lcs(s1,s2,n,m);
     
     cout<<(n+m-l)<<endl;
 }
	
	return 0;
}
