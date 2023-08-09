// =============================================================
// Amanzm 
// =============================================================
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}


// 01 BUBBLE SORT
void BubbleSort(int A[],int s){
int i,j;

    for ( i=1;i<s;i++)
    {
        for(j=1;j<=s-i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
            }
        }
    }

}
// 02 INSERTION SORT

void InsertionSort(int A[] , int s){
    int i,j,x;
    for(i=2;i<=s;i++)
    {
        x=A[i];j=i-1;
        while(j>=1 && A[j]>x)
             A[j+1]=A[j--];
         A[j+1]=x;
    }
}

// 03 SELECTION SORT
void SelectionSort(int A[], int n)
{
    int i,j,k;
    for (i=1;i<=n;i++)
    {
        k=i;
        for (j=i+1;j<=n;j++)
        {
            if(A[j]<A[k])
            k=j;
        }
        swap(&A[i],&A[k]);
    }
}
// 04 MERGE SORT

void MERGE(int A[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;

    int L[n1+1] ,R[n2+1];
    int i,j;
    for (i=1;i<=n1;i++)
    L[i]=A[p+i-1];

    for(j=1;j<=n2;j++)
    R[j]=A[q+j];

    L[n1+1]=INT_MAX;
    R[n2+1]=INT_MAX;

    int k;
    i=1,j=1;
    for(k=p;k<=r;k++)
    {
        if(L[i]<R[j])
            A[k]=L[i++];
        else
            A[k]=R[j++];
    }
   

}

void MergeSort(int A[], int p,int r)
{
    int q;
    if(p<r)
       {
         q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        MERGE(A,p,q,r);

        }
    

}

// 05 QUICK SORT

int PARTITION(int A[], int p, int r)
{
    int i,j,x;
    x=A[r] ;// Chosing last element as pivot
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            swap(&A[i],&A[j]);
        }
        
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}
void QuickSort(int A[], int p, int r)
{
    
    if(p<r)
    {

        /*  Add this piece to Implement RANDOMISED QUICK SORT
         int random =(rand()%(r-p+1))+p;
          swap(&A[r],&A[random]); */
        int q=PARTITION(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);

    }
}


int BinarySearch(int A[], int p, int r,int key){

    if(p<=r)
    {
        int q= p+(r-p)/2;    // same as (p+r)/2

        if(A[q]==key)
            return q;
        if(key>A[q])
            return BinarySearch(A,q+1, r,key);
        else 
            return BinarySearch(A,p,q-1,key);

    }

    return -1;

}



void Display(int A[],int size){
    int i;
            for (i=1;i<=size;i++)
            {
                    printf("%d ",A[i]);
            }
}



