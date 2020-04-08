#include<bits/stdc++.h>
#include <iostream>
using namespace std;

long long int max_sum(long long int ar[],long long int n)
{
     long long int cursum=0;
     long long int maxsum=0;
     long long int c=0;
     for(long long int i=0;i<n;i++)
       {
        if(ar[i]<0)
         c++;
        cursum=cursum+ar[i];
        if(cursum<0)
          cursum=0;
        maxsum=max(maxsum,cursum);
        }
       if(c==n) 
        return *max_element(ar,ar+n);
       else
        return maxsum;

}
