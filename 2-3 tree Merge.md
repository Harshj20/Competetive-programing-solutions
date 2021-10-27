You are given 2-3 trees T1 and T2, representing respectively finite sets S1, S2
of natural numbers. Further, it is given that for all x ∈ S1 and for all y ∈ S2, x < y.
Write a program to form a new 2-3 tree representing S1 U S2 with time compexity of O(H(T1) + H(T2)), 
where H(T) represents height of tree T.

```
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int a;
    int b;
    struct node*left;
    struct node*right;
    struct node*middle;
}node;

node*twonode(node*n1, node*n2, int t)
{
    node*p = (node*)malloc(sizeof(node));
    p->a = t;
    p->b = -1;
    p->left = n1;
    p->middle = n2;
    p->right = NULL;
    return p; 
}

node*MakeSkeleton(int x)
{
    node*p = (node*)malloc(sizeof(node));
    p->a = x;
    p->b = -1;
    p->left = NULL;
    p->right = NULL;
    p->middle = NULL;
    return p;
}

void extract(node*T)
{
    if(T->left == NULL)
    {
        printf("%d ", T->a); 
        return;   
    }
    extract(T->left);
    extract(T->middle);
    if(T->right != NULL)
    extract(T->right);
}

int height(node*a){
    int count = 0; 
    while(a->left != NULL)
    {
        count++;
        a = a->left;
    }
    return count;
}

node*insertright(node*ptr, node*s1, node*s2, int height_difference, int*flag)
{
    if(height_difference > 1)
    {
        if(ptr->right == NULL)
        s2 = insertright(ptr->middle, s1, s2, height_difference -1, flag);
        else
        s2 = insertright(ptr->right, s1, s2, height_difference -1, flag);
    }
    
    if(*flag == 1)
    return s2;

    if(ptr == s1)
    {
        if(ptr->right == NULL)
        {
            ptr->right = s2;
            ptr->b = s2->a;
            *flag = 1;
            return s1;
        }
        else
        {
            ptr->b = -1;
            node*temp = ptr->right;
            ptr->right = NULL;
            *flag = 1;
            int x = s2->a;
            return twonode(ptr, twonode(temp, s2,x),x);
        }
    }
    else if(ptr->right == NULL)
    {
        ptr->b = s2->a;
        ptr->right = s2;
        *flag = 1;
        return s1;
    }
    else
    
            ptr->b = -1;
            node*temp = ptr->right;
            ptr->right = NULL;
            return twonode(temp, s2, s2->a);

}
node*insertleft(node*ptr, node*s1, node*s2, int height_difference, int*flag)
{
if(height_difference > 1)
    {
        s1 = insertleft(ptr->left, s1, s2, height_difference -1, flag);
    }
    
    if(*flag == 1)
    return s1;

    if(ptr == s2)
    {
        if(ptr->right == NULL)
        {
            ptr->right = ptr->middle;
            ptr->b = ptr->a;
            ptr->a = ptr->left->a;
            ptr->middle=ptr->left;
            ptr->left = s1;
            *flag = 1;
            return s2;
        }
        else
        {
            ptr->a = ptr->b;
            ptr->b = -1;
            node*temp = ptr->left;
            ptr->left = ptr->middle;
            ptr->middle = ptr->right;
            ptr->right = NULL;

            *flag = 1;
            return twonode(twonode(s1, temp, temp->a), ptr, ptr->a);
        }
    }
    else if(ptr->right == NULL)
    {
        ptr->right = ptr->middle;
            ptr->b = ptr->a;
            ptr->a = ptr->left->a;
            ptr->middle=ptr->left;
            ptr->left = s1;
            *flag = 1;
            return s2;
    }
    else
    
           ptr->a = ptr->b;
            ptr->b = -1;
            node*temp = ptr->left;
            ptr->left = ptr->middle;
            ptr->middle = ptr->right;
            ptr->right = NULL;

            return twonode(s1, temp, temp->a);

}

node*merge(node*s1, node*s2)
{
    int h1 = height(s1), h2 = height(s2);
    if(h1 == h2)
    {
      return twonode(s1, s2, s2->a);
    }

    if(h1 > h2)
    {

        int flag = 0;
        return insertright(s1,s1, s2, h1-h2, &flag);
    }
    int flag = 0;
    return insertleft(s2 ,s1, s2, h2-h1, &flag);

}

void fun_Test()
{
    node*T = MakeSkeleton(1);

    for(int i = 2; i < 6; i++)
    T = merge(T, MakeSkeleton(i));

    node*U = MakeSkeleton(10);
    for(int i = 11; i < 17; i++)
    U = merge(U, MakeSkeleton(i));

    node*V = merge(T, U);
    extract(V);

}

int main()
{
    fun_Test();
    return 0;
}

```
