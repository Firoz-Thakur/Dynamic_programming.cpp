Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th 
character in the two subsequences shouldn’t have the same index in the original string.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the
length of string str.

The second line of each test case contains the string str consisting only of lower case english alphabets.

Output:

Print the length of the longest repeating subsequence for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=1000


Example:

Input:

2

3

abc

5

axxxy

Output:

0

2

Company Ta




you just have to find the longest subsequence(s1) and (s2) in s1 in where (s1==s2) and s.i != s1.i (i...n) (index of the string should not be same

other way : if we are condering some of the albhates at a one time as a lcs(s1) we can not considered those charater in second time for subsequece s2,...
apllying condtion s1==s2(where s1.i!=s2.i)



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int n)
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
            if(s1[i-1]==s2[j-1] && i!=j)
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
	while(t--)
	{
	    int n;
	    cin>>n;
	    cin.get();
	    string s;
	    cin>>s;
	    string s1;
	    for(int i=0;i<n;i++)
	    {
	        s1.push_back(s[i]);
	    }
	    
	  cout<<lcs(s,s1,n)<<endl; 
	    
	}
	return 0;
}
