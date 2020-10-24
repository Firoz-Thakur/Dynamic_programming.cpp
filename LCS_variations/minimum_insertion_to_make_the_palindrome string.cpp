
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3

 

Company Tags


















#include <iostream>
using namespace std;

 int palindromic_lcs(string s1,string s2,int n)
 {
     int dp[n+1][n+1];
     
     for(int i=0;i<=n;i++)
     {
         dp[i][0]=0;
     }
     for(int i=0;i<=n;i++)
     {
         dp[0][i]=0;
     }
     
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=n;j++)
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
     
     return dp[n][n];
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
	    
	   cout<<s1.size()-palindromic_lcs(s1,s2,s1.size())<<endl;
	   
	    
	    
	    
	}
	
	
	return 0;
}
