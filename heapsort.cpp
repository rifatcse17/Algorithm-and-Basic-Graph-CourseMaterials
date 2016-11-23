#include<stdio.h>
#include<iostream>
#include <bits/stdc++.h>  //header file
using namespace std;


void heapsort();           //function prototype
void max_heapify(int i);   //function prototype
void build_max_heap();     //function prototype


int a[1000],n;


//int n=8;
//int a[10]={0,3,41,52,26,38,57,9,49};
void max_heapify(int i){
    int l,r,largest;
    l=2*i;
    r=2*i+1;

    if(l<=n && a[l]>a[i])
        largest=l;
    else largest=i;


    if(r<=n && a[r]>a[largest])
        largest=r;

    if(largest!=i)
        {
            swap(a[i],a[largest]);
            max_heapify(largest);
        }
}
void build_max_heap(){
    int i;
    for(i=floor(n/2);i>=1;i--)
        max_heapify(i);
}
void heapsort(){
    int i;
    build_max_heap();
    for(i=n;i>=2;i--){
        swap(a[1],a[i]);
        n=n-1;
        max_heapify(1);
    }
}
int main(){
    int i;
      printf("Enter the number of input : ");

        scanf("%d", &n);

        int x = n;  // value of n is decreasing in hepa sort function of store it into x

        printf("\nEnter the elements to be sorted :\n");
        //printf("The random numbers are: ");
        for (i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("sorted array\n");

    heapsort();
    for(i=1;i<=x;i++)
        printf("%d ",a[i]);
    return 0;
}

