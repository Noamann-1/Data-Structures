#include<stdio.h>
void dupUnsorted(int *a,int n)
{
	int count =0;
	for(int i=0;i<n-1;i++)
	{
		count=1;
		if(a[i]!=-1)
		{
			for(int j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
			count++;
			a[j]=-1;
			}
		}
		if(count>1)printf("%d element %d times\n",a[i],count);
	}
		}
	
}
int main()
{
	int n=9;
	int A[10]={3,6,8,8,10,12,15,15,15,20};
	
	dupUnsorted(&A,n);
}
