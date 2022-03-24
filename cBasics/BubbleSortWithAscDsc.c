#include <stdio.h>
void bubble(int a[], int size, int (*myfun)(int a, int b));
void swap(int *a, int *b);
int ascending(int a, int b);
int descending(int a, int b);
int main(void)
{
    int array[]={6,4,8,14,10,16,12,2,18,20};
    int order,i;
    printf(" Array in original order:\n");
    for(i=0;i<10;i++)
        printf("%4d",array[i]);
    printf("\nEnter 1 to sort in ascending order, 2 to sort in descenfing order:");
    scanf("%d",&order);
    if(order==1)
        bubble(array,10,ascending);
    else 
        bubble(array,10,descending);
    printf(" \nArray in order:\n");
    for(i=0;i<10;i++)
        printf("%4d",array[i]);
    
    return 0;
}
void bubble(int a[], int size, int (*myfun)(int a, int b))
{
    int pass, i;
    for(pass=1;pass<size;pass++)
    {
        for(i=0;i<size-1;i++)
            if((*myfun)(a[i],a[i+1]))
                swap(&a[i],&a[i+1]);
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int ascending(int a, int b)
{
    return a>b;
}
int descending(int a, int b)
{
    return a<b;
}
