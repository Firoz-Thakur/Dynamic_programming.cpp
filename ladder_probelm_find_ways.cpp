#include <iostream>
using namespace std;

//top donw aprorach ->given n steps and maximum jump value,you need to find how many total ways are there to reach ate the top means at nth
step;


lets say 
n=4; now way can be find,first we assum that we are at top and we reached in this point as 
f(n)=f(n-1)+ f(n-2) + f(n-3)........++++++ f(n-k)

we are not taking care that how we reached at f(n-1) and 2,3,4,,,,so on

this condition will be handled by recursion itsself


base case :
 when n==0 return 1;
 
 mean we are at oth level so from ther to any of the step we have only one way.

int no_of_ways(int n,int k,int dp[])
{
	if(n==0)
	 return 1;
	if(dp[n]!=0)
	 return dp[n];
	int ways=0;
	for(int i=1;i<=k;i++)
	{
		if(n-i>=0){
		int subway =  no_of_ways(n-i,k,dp);
		ways=ways+subway;
		}
	}
 dp[n]=ways;
 return dp[n];
}


int main() {
	// your code goes here
	int n=4;
	int k=3;
	int dp[100]={0};
	cout<< no_of_ways(n,k,dp);
	return 0;
}

// bottom up dp time complexity o(n+k)

#include <iostream>
using namespace std;

int no_of_ways(int n,int k,int dp[])
{
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{ 
	   int way=0;
		for(int j=1;j<=k;j++)
		{
			if(i-j>=0)
			 {
			 	int subway=dp[i-j];
			 	way=way+subway;
			 }
		}
	dp[i]=way;
    }
	return dp[n];
}


int main() {
	// your code goes here
	int n=3;
	int k=3;
	int dp[100]={0};
	cout<< no_of_ways(n,k,dp);
	return 0;
}

//now space complexity o(n+k)
for int n=n and k=3;
we are getting array as [1,1,2,4,7,13,24]
it is the sum of previous three (k) term dp[n]=dp[n-1]+dp[n-2]+dp[n-3]

 dp[i]=={ 2 *dp[i-1] if i<k
       else
          2*dp[i-1] - dp[i-k-1] }

 we are using sliding window technique;
 we are adding n-1 element and substractin [n-k-1] element.
#include <iostream>
using namespace std;

int no_of_ways(int n,int k,int dp[])
{
 dp[0]=1;
 dp[1]=1;
 for(int i=2;i<=k;i++)
 {
 	dp[i]=2*dp[i-1];
 }
 for(int i=k+1;i<=n;i++)
 {
 	dp[i]=2*dp[i-1]- dp[i-k-1];
 }
 for(int i=0;i<=n;i++)
  cout<<dp[i]<<" ";                 1 1 2 4 7 13 24 44 81  (the same previous array)
 cout<<endl;                            
 return dp[n];                      81
}
int main() {
	// your code goes here
	int n=8;
	int k=3;
	int dp[100]={0};
	cout<< no_of_ways(n,k,dp);
	return 0;
}



