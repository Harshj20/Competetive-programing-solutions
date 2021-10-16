A coupon is a string of characters from a-z. An empty string is considered valid. 
For a particular string to be considered valid, following conditions must be met:
  1. the string is of the form XAX where A is a valid coupon and X is any character from a-z.
                    OR
  2. the string is of the form AB where A and B are valif coupon.
  
Input Format :
The first line will contain an integer n denoting the number of queries. The following n lines will contain n strings to be checked for validity.

Output Format :
The output will be given in the form of n different lines displaying the validity of n input strings. If the string is a valid coupon print 1, else print 0.

Constraints :
0 < |s| < 20, where |s| denote the length of string s.
0 < n < 100 where n is the number of queries.

Example :
```
Input 1
2
aa
abaaba 

output 1
1
1
```
```
Input 2
2
abcabc
adaadbba

Output 2
0
1
```

Below is the solution code in C
```
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
```
Note: The above solution is a very straighforward naive solution which can be categorised under Greedy algorithms. Hence it may not be the best Optimal solution.
