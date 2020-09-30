#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lcs(string a,string b)
{ 
 int m=a.size();
 int n=b.size();
 int dp[100][100];
 for(int i=0;i<100;i++)
  dp[i][0]=0;
 for(int j=0;j<100;j++)
  dp[0][j]=0;
 for(int i=1;i<=m;i++)
  {
  	for(int j=1;j<=n;j++)
  	{
  		int q=0;
  		if(a[i-1]==b[j-1])
  		   q=1+dp[i-1][j-1];  //diagonal
  		else
  		   q=max(dp[i-1][j],dp[i][j-1]); //finding the maximum of previus colum and roows
  	
  	    dp[i][j]=q;
  	}
  }
 return dp[m][n];  
}
int main() {
	// your code goes here
	string s;
	string s2;
	cin>>s>>s2;
	cout<<lcs(s,s2);
	return 0;
}


//recursive solution
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int lcs(string s1,string s2,int i,int j,int dp[101][101])
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



int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    cin.get();
	    string s1,s2;
	    cin>>s1>>s2;
	    int dp[101][101];
	    for(int i=0;i<n1;i++)
	    {
	        for(int j=0;j<n2;j++)
	        {
	            dp[i][j]=-1;
	        }
	    }
	   int l=lcs(s1,s2,0,0,dp);
	   cout<<l<<endl;
	    
	}
	
	
	
	
	return 0;
}
