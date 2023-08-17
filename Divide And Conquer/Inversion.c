// =============================================================
// Amanzm 
// =============================================================
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


int Inversion_merge(int A[],int p,int q,int r)
{ int inv=0;
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
            {A[k]=R[j++];
            inv+=n1-i+1;}
    }
   
return inv;
}

int Inver_MergeSort(int A[], int p,int r)
{
    int q,inv=0;
    if(p<r)
       {
         q=(p+r)/2;
       inv+= Inver_MergeSort(A,p,q);
        inv+=Inver_MergeSort(A,q+1,r);
       inv+= Inversion_merge(A,p,q,r);

        }
        return inv;
    

}







void Display(int A[],int size){
    int i;
            for (i=1;i<=size;i++)
            {
                    printf("%d ",A[i]);
            }
}

int main()
{
    int s;
    printf("Enter Size of Array\n");
   
    scanf("%d",&s);
    int A[s+1];
    printf("Enter Elements of Array\n");
     for(int k=1;k<=s;k++)
     scanf("%d",&A[k]);
    

   
          int  i= Inver_MergeSort(A,1,s);
            printf("%d ",i);
           // Display(A,s);
           

}


