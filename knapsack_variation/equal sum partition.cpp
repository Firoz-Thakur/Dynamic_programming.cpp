Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

https://leetcode.com/problems/partition-equal-subset-sum/

 Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
Accepted
213,485
Submissions
483,020




class Solution {
public:
    
   int  dp[202][50000];
    
   bool help(vector<int>& ar,int sum,int left,int n)
   {
       if(sum==left)
       {
           return true;
       }
      if( n==0)
           return false;
      
     if(dp[n][sum]!=-1)
          return dp[n][sum];
     
      dp[n][sum]=help(ar,sum,left,n-1) || help(ar,sum-ar[n-1],left+ar[n-1],n-1);  
       
       return dp[n][sum];
   }
    
    
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        int n=nums.size();
        return help(nums,sum,0,n);    
    }
};
