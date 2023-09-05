// Aman Modan
// 11 Aug fri 5:00 pm
#include<stdio.h>


   int digIn(int n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) 
    {
        n = n / 10;
        ++count;
    }
    return count;
}

int power(int a, int b)
{
int result=1;
for(int i=0;i<b;i++) result*=a;
return result;
}

// Karatsuba 
 long long int Karatsuba(long long int x, long long int y , long long int n1, int  n2)
{ 
    if(x<10||y<10) return x*y; //Base case

    int half=((n1>n2)?n1:n2)/2; 
    int z=power(10,half);

     int a= x/z, b=x%z, c=y/z, d=y%z;

 // 3 Recursive Calls
long long int ac=Karatsuba(a,c,digIn(a),digIn(c));
long long int bd=Karatsuba(b,d,digIn(b),digIn(d));
long long int ad_plus_bc=Karatsuba(a+b,c+d,digIn(a+b),digIn(c+d))-ac-bd;

return ((ac*(power(10,half*2)))+(ad_plus_bc)*(z)+(bd));
}


int main()
{
    long long int num1,num2;
    printf("Enter First Number\n");
    scanf("%lld",&num1);
    printf("Enter Second Number\n");
    scanf("%lld",&num2);

long long int result=Karatsuba(num1,num2,digIn(num1),digIn(num2));
     printf("%lld",result);
    return 0;

}



