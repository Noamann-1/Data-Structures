#include<stdio.h>
#include<string.h>
int main()
{
	char s1[]="decimal";
	char s2[]="medical";
	if(strlen(s1)!=strlen(s2))
	return 0;
	int i=0;int H[26]={0};
	for(;s1[i]!='\0';i++)
	{
		H[s1[i]-97]+=1;
	} 
	for(i=0;s2[i]!='\0';i++)
	{
		H[s2[i]-97]-=1;
	}
	for(i=0;s1[i]!='\0';i++)
	{
		if(H[s1[i]-97]!=0)
		return 0;
	}
	if(s1[i]=='\0')
	printf("%s and %s are anagram",s1,s2);
}
