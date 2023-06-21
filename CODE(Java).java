/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		
		    int n=Integer.parseInt(br.readLine());
		    if(n==1)
		    {
		        System.out.println("1");return;
		    }
		    else if(n==2)
		    {
		        System.out.println("2");return;
		    }
		    long a[]=new long[n];
		    StringTokenizer tk=new StringTokenizer(br.readLine());
		    for(int i=0;i<n;i++)
		    a[i]=Long.parseLong(tk.nextToken());
		    long dpx[][]=new long[n][n];
		    for(int i=1;i<n;i++)
		    {
		        for(int j=0;j<i;j++)
		        dpx[i][j]=a[i]^a[j];
		    }
		    int dpl[][]=new int[n][n];
		    dpl[0][0]=1;
		    dpl[1][0]=2;int max=2;
		    for(int i=2;i<n;i++)
		    {
		        for(int j=0;j<i;j++)
		        {
		            long v=dpx[i][j];
		            int m=-1;
		            for(int k=0;k<j;k++)
		            {
		                if(dpx[j][k]<=v)
		                m=(int)Math.max(m,dpl[j][k]);
		            }
		            if(m==-1)
		            dpl[i][j]=2;
		            else
		            dpl[i][j]=m+1;
		            max=(int)Math.max(dpl[i][j],max);
		        }
		    }
		    System.out.println(max);
		
	}
}