#include<stdio.h>
int main()
{
	char s[]="FinDiNg";
	int h=0;int x;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>= 'A' && s[i]<= 'Z')
		{
			s[i]+=32;
		}
		x=1;
		x=x<<(s[i]-97);
		if(h&x)
		{
			printf("%c duplicate\n",s[i]);
		}
		else
		h=h|x;
	}
}
