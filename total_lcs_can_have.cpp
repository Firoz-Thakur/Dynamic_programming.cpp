Given an array of digits (values lie in range from 0 to 9). The task is to count all the sub sequences possible in array such that in each subsequence every digit is greater 
than its previous digits in the subsequence.

Examples:

Input : arr[] = {1, 2, 3, 4}
Output: 15
There are total increasing subsequences
{1}, {2}, {3}, {4}, {1,2}, {1,3}, {1,4}, 
{2,3}, {2,4}, {3,4}, {1,2,3}, {1,2,4}, 
{1,3,4}, {2,3,4}, {1,2,3,4}

Input : arr[] = {4, 3, 6, 5}
Output: 8
Sub-sequences are {4}, {3}, {6}, {5}, 
{4,6}, {4,5}, {3,6}, {3,5}

Input : arr[] = {3, 2, 4, 5, 4}
Output : 14
Sub-sequences are {3}, {2}, {4}, {3,4},
{2,4}, {5}, {3,5}, {2,5}, {4,5}, {3,2,5}
{3,4,5}, {4}, {3,4}, {2,4}
Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of digits.
The second line contains N space-separated digits.

Output:
Count of all increasing subsequences in given array of digits.


Constraints:
1 ≤ T ≤ 30
1 ≤ N ≤ 500


Example:
Input:
2
5
3 2 4 5 4
3
1 2 4
Output:
14
7




#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code\
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>ar[i];
	    }
	    
	    int dp[n];
	    for(int i=0;i<n;i++)
	    {
	       // dp[i]=1;
	        int sum1=0;
	        for(int j=0;j<i;j++)
	        {
	            if(ar[j]<ar[i])
	            {
	                sum1=sum1+dp[j];
	            }
	            
	        }
	        dp[i]=sum1+1;
	    }
	    long long int  sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum=sum+dp[i];
	    }
	    
	    cout<<sum<<endl;
	}
	return 0;
}
