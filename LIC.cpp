#include <iostream>
using namespace std;

input : 50 3 10 7 40 50
output : 4(3,10,40,50) or (3,7,40,50)

int lic(int ar[],int n)
{
	int dp[100];
	for(int i=0;i<n;i++)
	 dp[i]=1;
	int maxsub=-1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(ar[j]<=ar[i])
			{
				int cursum=1+dp[j];
				dp[i]=max(cursum,dp[i]);
			}
		}
	 maxsub=max(maxsub,dp[i]);
	
	}
for(int i=0;i<10;i++)
	 cout<<dp[i]<<" ";
	cout<<endl;
return maxsub;
}



int main() {
	// your code goes here
	int ar[]={10,22,9,33,21,50,41,60,80,6};
	int n=10;
	cout<<lic(ar,n);
	return 0;
}



input :10,22,9,33,21,50,41,60,80,6.
output :1 2 1 3 2 4 4 5 6 1 
6
