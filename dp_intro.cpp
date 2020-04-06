//simple recursion solution of fibonnacai number time complexity expotential.
#include <iostream>
using namespace std;

int fib(int n)
{
	if(n==0 || n==1)
	 return n;
	int ans;
	ans=fib(n-1)+ fib(n-2);
	return ans;
}
int main() {
	// your code goes here
	int n=5;
	cout<<fib(n);
	return 0;
}

// dp using top down dp,recursion + momoriazation.

#include <iostream>
using namespace std;

int fib(int n)
{
	if(n==0 || n==1)
	 return n;
	int ans;
	ans=fib(n-1)+ fib(n-2);
	return ans;
}
int main() {
	// your code goes here
	int n=12;
	cout<<fib(n);
	return 0;
}

//bottom up fibbonacai

#include <iostream>
using namespace std;

int fibBU(int n)
{
  int dp[100]={0};
  dp[1]=1;
  for(int i=2;i<=n;i++)
  {
  	dp[i]=dp[i-2]+dp[i-1];
  }
  return dp[n];
}
int main() {
	// your code goes here
	int n=12;
	cout<<fibBU(n);
	return 0;
}

//now fibonaccai bottom up with space O(1) and time complexity o(n)

#include <iostream>
using namespace std;

int fibBU(int n)
{
  if(n==0 || n==1)
   return n;
  int a=0;
  int b=1;
  int c;
  for(int i=2;i<=n;i++)
  {
  	c=a+b;
    a=b;
  	b=c;
  
  }
  return c;
}
int main() {
	// your code goes here
	int n=12;
	cout<<fibBU(n);
	return 0;
}
