#include<stdio.h>
#include<stdlib.h>


float XY(float x , int y)
{
	if(y==0)
	return 1;
	 float p = XY(x,y/2);
	if(y&1)return p*p*x;
	else return p*p;
}




int main(){


 FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

   

  float x; int y;
        fscanf(inputFile, "%f", &x); // Read the array elements
    	fscanf(inputFile, "%d", &y);

fprintf(outputFile, " answer:  %f\n", XY(x,y));



return 0;}
