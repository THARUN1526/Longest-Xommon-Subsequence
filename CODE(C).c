#include <stdio.h>


 int xcs( int n,long long int a[])
{
    int dp[n],i;
   dp[0]=0;
   dp[1]=1;
   long long int min=a[0]^a[1];
   for(i=2;i<n;i++)
   {
      if(a[i-1]^a[i]>min) 
      {
          min=a[i-1]^a[i];
          dp[i]=dp[i-1]+1;
          
      }
      else
      {
          dp[i]=dp[i-1];
      }
   }
   
  return dp[n-1];  
    
}

int main(void) {
	
	 int i,n,l;
	scanf("%d",&n);
	long long int a[n];
	for(i=0;i<n;i++)
	{
	    scanf("ll%d",&a[i]);
	}

	l=xcs(n,a);
	printf("%d",l);
	
	return 0;
}
