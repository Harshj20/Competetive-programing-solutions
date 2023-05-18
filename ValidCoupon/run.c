#include <stdio.h>
#include <string.h>

int check( char*s, int i, int j)                         \\ this function checks the validity of a substring of string s, where i and j are the starting                                                              
{                                                        \\ and ending indexes of the substring
    if(s[i] == s[j] && i == j+1){                        \\ this is the base case for the recursive call
        return 1;
    }
    if(s[i] == s[j])                                      \\ this part is to check the validity of a string of the form XAX
    {
        return check(s, i+1, j-1);
    }
    int k = j;
    while(i < k)                                         \\ this part is to divde the string into substring i.e. to check the string of the form ABC by splitting it into
    {
        if(s[i] == s[k])                                  \\ substing A and BC.
        break;
        k = k-2;
    }
    if(k <= i)
    return 0;
    
    return check(s, i+1, k-1) && check(s, k+1, j);
    
}

int main()
{
    int n;
    scanf("%d ", &n);
    char s[20];

    for(int i = 0; i < n; i++)
    {
        scanf("%s\n", s);
        
        if(strlen(s)%2 == 0)
        
        printf("%d\n",  check(s, 0, strlen(s)-1));
        
        else printf("%d\n",  0);
    }
    return 0;
}
