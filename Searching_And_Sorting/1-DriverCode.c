#include<stdio.h>
#include<stdlib.h>

#include "1-Sorting_Searching.c"



void output(int A[],int s )
{
    FILE * fp2;
int i;
fp2=fopen("output.txt","w");
for(i=1; i<=s &&(!feof(fp2));i++)
{
    fprintf(fp2,"%d  ",A[i]);
}
fclose(fp2);
}


int main()
{
    int s;
    printf("Enter Elements you want to read  from file \n");
   
    scanf("%d",&s);
    int *A=(int *)malloc(sizeof(int)*(s+1));
int i=1;
FILE * fp;
fp=fopen("input.txt","r");
int n;
while(!feof(fp) && i<=s )
{
fscanf(fp,"%d",&n);
A[i++]=n;
printf("%d" ,n);

}
fclose(fp);







    // printf("Enter Elements of Array\n");
    //  for(int k=1;k<=s;k++)
    //  scanf("%d",&A[k]);
    int z;
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
     printf("3. Selection Sort\n");
    printf("4. Merge Sort\n");
     printf("5. Quick Sort\n");
     printf("6. Binary Search\n");


 printf("Enter Your Choice\n");
 scanf("%d",&z);

    switch(z){
        case 1:
            
            BubbleSort(A,s);
            Display(A,s);
            output(A,s);
            break;
        case 2:
            InsertionSort(A,s);
            Display(A,s);
            output(A,s);

            break;
         case 3:
         SelectionSort(A,s);
            Display(A,s);
            output(A,s);
            break;
        case 4:
             MergeSort(A,1,s);
            Display(A,s);
            output(A,s);
            break;
        case 5:
            
            QuickSort(A,1,s);
            Display(A,s);
            output(A,s);
            break;
        case 6:
            printf("Enter Key Value\n");
            int k; scanf("%d",&k);
            printf(" At index :%d\n",BinarySearch(A,1,s,k));
            Display(A,s);
            break;
        default:
             printf("Enter proper value\n");

    }


}
