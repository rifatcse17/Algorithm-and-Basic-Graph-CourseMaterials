#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define inf 1<<28

void m_sort(int, int);
void marge(int, int ,int);
int A[100];

int main()
{
    int n;

    printf("How Many Elements ? \n");
    scanf("%d", &n);
    printf("Enter The Elements \n");

    for(int x=1; x <= n; x++)
        scanf("%d", &A[x]);

    //for(int i=0; i < 5; i++)
        //printf("%d ", A[i]);

    int z = 1;
    m_sort(z,n);

    printf("\nSorted Array :\n");

    for(int i=1; i <= n; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}

void m_sort(int p, int r)
{
    int q;
    if( p < r)
        {
            q = (p+r)/2;
            m_sort(p,q);
            m_sort(q+1, r);
            marge(p, q, r);
        }
}

void marge(int p, int q, int r)
{
    //int i,j,k;
    int n1 = q-p+1;
    int n2 = r-q;

    int L[100], R[100];

    for(int i = 1; i <= n1; i++)
        L[i] = A[p+i-1];

    for(int j = 1; j <= n2; j++)
        R[j] = A[q+j];

    L[n1+1] = 1000;
    R[n2+1] = 1001;
    int i = 1;
    int j = 1;

    for(int k = p ; k <= r; k++)
        {
            if(L[i] <= R[j])
                {
                    A[k] = L[i];
                    i = i+1;
                }
            else
                {
                    A[k] = R[j];
                    j = j+1;
                }
        }
}
