// Aman Modan
 // This is modified version of previous  it also gives maximum subarrays starting and ending index!


#include<stdio.h>
#include<limits.h>

// Divide and Conquer


 typedef struct Subarr{
int sum;
int l;
int h;
}Subarr;

struct Subarr Max_Crossing_Sub(int A[],int l, int m ,int h)
{
    int left_sum=INT_MIN,left;
    int sum=0;
    for(int i=m;i>=l;i--)
    {
        sum+=A[i];
        if(sum>left_sum)
        {left_sum=sum;
        left=i;
        }
    }
    int right_sum=INT_MIN,right;
    sum=0;
    for(int i=m+1;i<=h;i++)
    {
        sum+=A[i];
        if(sum>right_sum)
        {right_sum=sum; 
        right=i;
        }  
    }
    struct Subarr result;
result.sum=left_sum+right_sum;
result.l=left;
result.h=right;

 return result;


}


struct Subarr Max_Sum_Sub(int A[],int l, int h){

    if(l==h)
    {struct Subarr res;
    res.sum=A[l];
    res.h=res.l=l;
    return res;}

    int m=(l+h)/2;

    struct Subarr leftArr=Max_Sum_Sub(A,l,m);
    struct Subarr  rightArr= Max_Sum_Sub(A,m+1,h);
    struct Subarr crossArr=Max_Crossing_Sub(A,l,m,h);

    if(leftArr.sum>=rightArr.sum && leftArr.sum>=crossArr.sum)
    return leftArr;
else if(rightArr.sum>=leftArr.sum && rightArr.sum>=crossArr.sum)
    return rightArr;
else
    return crossArr;
}

int main(){
    int A[]={0,-2,1,-3,4,-1,2,1,-5,4};


    struct Subarr result=Max_Sum_Sub(A,1,6);
   //int k= maxSubArray(A,9);
   printf("Sum of Max Sub array is :%d\n Starting Index is : %d\n Ending Index is : %d\n ",result.sum ,result.l,result.h);
}