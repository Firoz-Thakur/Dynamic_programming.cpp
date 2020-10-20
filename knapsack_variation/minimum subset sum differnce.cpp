Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the
minimum difference

Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   
Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

Your Task:  
You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value

Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)





	int minDiffernce(int ar[], int n) 
	{ 
	    // Your code goes 
	   int range=0;
	   
	   
	   //subset sum problem code 
	   for(int i=0;i<n;i++)
	   {
	       range=range+ar[i];
	   }
	   int dp[n+1][range+1];
	   
	   for(int i=0;i<=range;i++)
	   {
	       dp[0][i]=false;;
	   }
	   for(int i=0;i<=n;i++)
	   {
	       dp[i][0]=true;
	   }
	   
	   for(int i=1;i<=n;i++)
	   {
	       for(int j=1;j<=range;j++)
	       {
	           if(ar[i-1]<=j)
	           {
	               dp[i][j] = dp[i-1][j-ar[i-1]] || dp[i-1][j];
	           }
	           else
	           {
	               dp[i][j] = dp[i-1][j];
	           }
	       }
	   }
     
     // we have to find ,s1-s2=minimum.
     we know that if there is s1 there would also be s2 on the other side,mean s1+s2=range(total sum of the array)
     
     s1-s2=minimum
     range-s2-s2=minim
     range - 2*s2 =min
     
     we have considered that s1> s2
     s2 will lie  left side of range/2,and s1 will lie on the right side of the range/2,
	
	Input: N = 4, arr[] = {1, 6, 11, 5} 
	
	for the input ,the range will be 0 to 23
       
         betwenn o to 23 in the last row of the matrix we will get the for wich of the number the subset is posible.
		 
	 
	0,1,5,6,7,11,|| 12,16,17,18,22,,23 -----range
        all these values are in pair by just knowing the s1 till range/2 we can get s2 as well
		 
     
	  vector<int> v;  
	    
	  for(int i=0;i<=range/2;i++)
	  {
	      if(dp[n][i]==true)
	       v.push_back(i);
	    
	  }
	  
	  
	  int m=INT_MAX;
	  for(int i=0;i<v.size();i++)  
	    {
	       // cout<<v[i]<<" ";
	        m=min(m,range-2*v[i]);
	        
	    }
	 return m;   
	} 
};
