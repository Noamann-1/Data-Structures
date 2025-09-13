#include<stdio.h>
void numOfDup(int *a,int n)
{
	int j;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			j=i+1;
			while(a[j]==a[i])j++;
			printf("%d %d times \n",a[i],j-i);
			i=j-1;
		}
	}
}
void numOfDupHash(int *a,int n)
{
	int h,l,i;
	h=a[0];
	l=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>h)
		{
			h=a[i];
		}
		if(a[i]<h)
		{
			h=a[i];
		}
	}
	int H[h];
	for(i=0;i<h;i++)
	{
		H[i]=0;
	}
	for(i=0;i<n;i++)
	{
		H[a[i]]++;
	}
	for(i=0;i<h;i++)
	{
		if(H[i]>1)
		printf("%d-->%d times\n",i,H[i]);
	}
}
int main()
{
	int size=10;
	int A[10]={3,6,8,8,10,12,15,15,15,20};
	numOfDupHash(&A,size);
}
