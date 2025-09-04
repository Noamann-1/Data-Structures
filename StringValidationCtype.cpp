#include <stdio.h>
#include <ctype.h>

int validate(char *s)
{
	int i=0;
    while (s[i]!='\0')
    {
        if (!(isalnum(s[i]) || s[i] == '-' || s[i] == '_' || s[i] == '@'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main()
{
    char A[] = "kindiBindi_1";
    char B[] = "contact@me";
    char C[] = "Wrong#Name";

    printf("%s is %s\n", A, validate(A) ? "valid" : "invalid");
    printf("%s is %s\n", B, validate(B) ? "valid" : "invalid");
    printf("%s is %s\n", C, validate(C) ? "valid" : "invalid");

    return 0;
}

