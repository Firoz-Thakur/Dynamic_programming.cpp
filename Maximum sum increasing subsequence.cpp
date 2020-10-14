Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.



Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}
Your Task:  
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 105

Company Tags
Topic Tags


If you are facing any issue on this page. Please let us know.




int maxSumIS(int ar[], int n)  
	{  
	    // Your code goes here
	    

	int dp[1000000];
	int maxsub=-1;
	for(int i=0;i<n;i++)
	{
        dp[i]=ar[i];
		for(int j=0;j<i;j++)
		{
			if(ar[j]<ar[i])
			{
				int cursum=ar[i]+dp[j];
				dp[i]=max(cursum,dp[i]);
			}
		}
	 maxsub=max(maxsub,dp[i]);
	
	}
return maxsub;
