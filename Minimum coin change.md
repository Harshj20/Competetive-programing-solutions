Given an amount and the denominations of coins available, determine change which can be made for amount using minimum no. of total coins. There is a limitless supply of each coin type.

#### Input format:
1. first line of input contains total number of denominations, say n.
2. second line contain n single space separated integers in increasing order denoting values of denominations.
3. third line contains the amount x.

#### Sample Input
```
4
2 7 11 19
82
```

#### Sample Output
```
6
```

Minimum change can be made using 2 coins with value 19 and 4 coins with value 11 making the total 6 coins amounting to 82.

Code in C
~~~
#include<stdio.h>

#define Max 9999999

int findChange(int*a, int i, int x)
{
    if(i < 0)
    {
        return (x == 0)?0:Max;
    }
    if(x == 0)
    return 0;
    int q = x/a[i];
    int min = Max, temp = 0;
    while(q >= 0)
    {
        temp =q+findChange(a, i-1, x-q*a[i]);
        if(min > temp)
        min = temp;
        q--;
    }
    return min;
}

int main(){
    int n, x;                        // n = no. of denominations, x is the amount
    scanf("%d", &n);
    int a[n];                        // store the denominations in increasing order
    for(int i = 0; i < n; i++)
    {
        scanf("%d ", a+i);
    }
    scanf("%d", &x);
    printf("Ans : %d", findChange(a, n-1, x));
}
~~~
