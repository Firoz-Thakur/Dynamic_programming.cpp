//road cutting problem is same as unbounded knapsack:(exactly same)


Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input:
First line consists of T test cases. First line of every test case consists of n, denoting the size of array. Second line of every test case consists of price of ith length piece.

Output:
For each testcase, in a new line, print a single line output consists of maximum price obtained.

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= Ai <= 100

Example:
Input:
1
8
1 5 8 9 10 17 17 20
Output:
22














#include <iostream>
using namespace std;

int unknapsack(int wt[],int val[],int n)
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
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
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
	    int wt[n];
	    int val[n];
	    for(int i=0;i<n;i++)
	    {
	        wt[i]=i+1;
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>val[i];
	    }
	    
	    cout<<unknapsack(wt,val,n)<<endl;
	}
	return 0;
}
