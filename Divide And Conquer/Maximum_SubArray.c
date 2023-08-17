// Aman Modan
 //******Note Indexing from 1 is used!!.


#include<stdio.h>
#include<limits.h>

// Divide and Conquer

int maxim(int a,int b,int c){

    return (a>b)?((a>c) ?a:c):((b>c)?b:c);
}

int  Max_Crossing_Sub(int A[],int l, int m ,int h)
{
    int left_sum=INT_MIN;
    int sum=0;
    for(int i=m;i>=l;i--)
    {
        sum+=A[i];
        if(sum>left_sum)
        left_sum=sum;
    }
    int right_sum=INT_MIN;
    sum=0;
    for(int i=m+1;i<=h;i++)
    {
        sum+=A[i];
        if(sum>right_sum)
        right_sum=sum;   
    }

 return (left_sum+right_sum);

}


int Max_Sum_Sub(int A[],int l, int h){

    if(l==h)
    return A[l];

    int m=(l+h)/2;
    return maxim(Max_Sum_Sub(A,l,m),Max_Sum_Sub(A,m+1,h),Max_Crossing_Sub(A,l,m,h));
}

//Dynamic Programming
int maxSubArray(int A[], int b){
    int sum=0, max=A[0];
    
    for(int i=0;i<b;i++)
    {
        sum+=A[i];
        if(sum>max)max=sum;
        if(sum<0)sum=0;
    }
    return max;

}
int main(){
    int A[]={0,-1,-2,-1,-2};


    // int result=Max_Sum_Sub(A,1,9);
//    printf("%d",result);
   int k= maxSubArray(A,4);   printf("%d",k);

}