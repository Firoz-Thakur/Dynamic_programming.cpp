given : an array we have to find the count of the tho sum subset s1 and s2 haiving s1-s2=diff(given)


given 
      s1-s2=diff;
also  s1+s2=sum_of_the_aray
 by elemination :
     
     2s1=diff+sum_of_the_arrya.
     s1=(diff+sum_of_the_arrya)/2;


now we have to find the count of the subset having sum s1 in the given array.





#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//#define ll long long
int main()
{
 int n;
 cin>>n;
 int diff;
 cin>>diff;
 int ar[n];
 int sum=0;
 for(int i=0;i<n;i++)
 {
     cin>>ar[i];
     sum=sum+ar[i];
 }
 
 int sum1=(sum+diff)/2;

  find_the_subset(ar,sum1);

}
