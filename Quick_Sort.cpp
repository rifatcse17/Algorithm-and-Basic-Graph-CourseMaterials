#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int partition (int [], int, int );
void quickSort(int [], int, int);

int main()
{
    int A[100],n;

   // freopen("e:/in.txt","r",stdin);

    printf("How Many Elements ? \n");
    scanf("%d", &n);
    printf("Enter The Elements \n");
    for(int x=0; x < n; x++)
        scanf("%d", &A[x]);

    quickSort(A, 0, n-1);

    printf("\nSorted Array\n");

    for(int i=0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}

void quickSort(int A[], int p, int r)
{
    int q;
    if( p < r )
        {
            q = partition(A, p, r);
            quickSort(A, p, q-1);
            quickSort(A, q+1, r);
        }
}

int partition(int A[], int p, int r)
{
    int temp, j, x = A[r];
    int i = p-1;

    for(j = p; j <= r-1; j++)
        {
            if(A[j] <= x)
                {
                    i = i+1;
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
        }
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return i+1;
}
