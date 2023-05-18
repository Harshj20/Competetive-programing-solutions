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