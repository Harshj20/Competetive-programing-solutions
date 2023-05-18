#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int ver;
    struct node*next;
}node;

void insert(node**a, int b)
{
    node*temp = (node*)calloc(1, sizeof(node));
    temp->ver = b;
    temp->next = *a;
    *a = temp;
}

int Bipartite(node**g, int*a, int i)
{
    node*temp = g[i];
    while(temp != NULL)
    {
        if(a[i] == a[temp->ver])                      // condition to tell whether the graph is bipartite or not
        return 0;
        
        int x = a[temp->ver];
        
        a[temp->ver] = (a[i])%2 + 1;
        
        if(!x)                                         // this helps to avoid going to a vertices and its neighbour again thus reducing time
        {
            if(!Bipartite(g, a, temp->ver))
            return 0;
        }
        
        temp = temp->next;
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    node**G;
    G = (node**)calloc(n, sizeof(node*));
    
    int a[n];                                       // keeps the record which vertice belong to which set ( v1 or v2)
    
    for(int i = 0; i < n; i++)                       // initializing G, a
    {
        G[i] = NULL;
        a[i] = 0;
    }
    
    a[0] = 1;                                       // vertex 0 belong to V1

    for(int i = 0; i < k; i++)                      // making of adjacency list
    {
        int a, b;
        scanf("%d %d", &a, &b);
        insert(G+a, b);
        insert(G+b, a);
    }
    
    int v1 = 0, v2 = 0;                              //getting the ans and initializing V1, V2
    int x = Bipartite(G, a, 0);
        node*V1 = (node*)calloc(1, sizeof(node));
        node*V2 = (node*)calloc(1, sizeof(node));
    
    
    if(!x)
    {
        free(V1);
        free(V2);
        printf("NO");
    }
    else
    {
        printf("YES\n");

        for(int i = 0, j = 0, k = 0; i < n; i++)
        {
             printf("%d\n", a[i]);
             if(a[i] == 1)                                                // for partitioning V1 and V2
             {
                 v1++;
                 V1 = (node*)realloc(V1, v1*sizeof(node));
                (V1[j]).ver= i;
                (V1[j]).next=G[i];
                 j++;
             }  
            else
             {
                v2++;
                V2 = (node*)realloc(V2, v2*sizeof(node));
                (V2[k]).ver= i;
                (V2[k]).next=G[i];
                k++;
             }  
        }  
    }
    
    // if(x)                                                  This is to check whether the V is partitioned into V1 and V2 correctly
    // {
    //     for(int i = 0; i < v1 ; i++)              
    //     {
    //         node*temp =V1[i].next;
    //         printf("\n%d: ",V1[i].ver);
    //         while(temp != NULL)
    //         {
    //             printf("%d ", temp->ver);
    //             temp = temp->next;
    //         }
    //     }
    // }
    return 0;
}