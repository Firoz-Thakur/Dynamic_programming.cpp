Given a set of n non-negative integers, and a value m, determine if there is a subset of the given set with sum divisible by m.

Example 1:

Input: 
n = 4 m = 6 
nums[] = {3 1 7 5}
Output:
1
Explanation:
If we take the subset {7, 5} then sum
will be 12 which is divisible by 6.
Example 2:

Input:
n = 3, m = 5
nums[] = {1 2 6}
Output:
0
Explanation: 
All possible subsets of the given set are 
{1}, {2}, {6}, {1, 2}, {2, 6}, {1, 6}
and {1, 2, 6}. There is no subset whose
sum is divisible by 5.


















  int dp[1002][1006];
  
    int solve(vector<int> num,int n,int m,int ans)
	 {
	  
	  if(ans%m==0 && ans!=0)
	  {
	      return 1;
	  }
	  if(n==0)
	   return false;
	  
	   if(dp[n][ans]!=-1)
	    {
	       return dp[n][ans];
	    }
	
	 
	     dp[n][ans]= solve(num,n-1,m,ans+num[n-1]) || solve(num,n-1,m,ans);
	 
  
	 return dp[n][ans];
	    
	}


		int DivisibleByM(vector<int>nums, int m){
		    // Code here
		  int n=nums.size(); 
		  
		  memset(dp,-1,sizeof(dp));
		  int x=solve(nums,n,m,0);  
		  
		    return x;
		    
		}
