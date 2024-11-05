#include<stdio.h>

int main(){
	
	int x[5];
	double avg=-5.0;
	x[0]= 10;
	x[1]= 7;
	x[2]= 5;
	x[3]= 9;
	x[4]= 10;
	double sum = 0.0;//sum 41
	for (int i = 0 ;i < 5; ++i)
		{
		sum +=x[i];
		printf("for i = %d, sum = %lf \n ", i, sum );
			
		} 
	avg = sum/5;
	printf("the average score is: %lf \n", avg);
}



/*
   this code calculates the average of the 5 numbers which are 10,7,5,9,10 
   gives the result of average score as  8.200000 
//at each iteration  it calculates the sum of current and previous numbers and gives the sum result in each iteration

the ouput of the code is

for i = 0, sum = 10.000000 
 for i = 1, sum = 17.000000 
 for i = 2, sum = 22.000000 
 for i = 3, sum = 31.000000 
 for i = 4, sum = 41.000000 
 the average score is: 8.200000 
   
*/
