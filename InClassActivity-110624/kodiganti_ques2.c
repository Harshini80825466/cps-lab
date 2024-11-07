#include<stdio.h>
#include<math.h>

int main(){
	
	int x[5];
	double avg=-5.0;
	x[0]= 10;
	x[1]= 7;
	x[2]= 5;
	x[3]= 9;
	x[4]= 10;
    int n=5;
    
	double sum = 0.0;//sum 41
	for (int i = 0 ;i < 5; ++i)
		{
		sum +=x[i];
		printf("for i = %d, sum = %lf\n", i, sum );
			
		} 
	avg = sum/5;
	printf("the average score is: %lf \n", avg);



printf("array length %d\n", n);

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
	float mean=0;
	mean  = sum/n;
	printf("mean %f\n", mean);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(x[i]<x[j])
			{
				int t=x[i];
				x[i]=x[j];
				x[j]=t;
			}
		}
	}

	float median;
	if(n%2==0)

		median=( (x[(n-1)/2] + x[(n-1)/2+1] ) / 2.0);

	else

		median=( (x[(n)/2]) );


	printf("median is %.1f\n",median);



	int mode;
	int c =0;
	int max;


	for(int i=0; i<n; i++)

	{

		int t=x[i];

		c=0;

		for(int j=0; j<n; j++) {
			if(t==x[j]) c++;
			if(c>max)

			{

				max=c;

				mode=t;

			}

		}

	}

	printf("mode is %d\n",mode);
    

	float stdDeviation;
    float variance;
	for (int i = 0; i < n; i++) {
		variance += pow(x[i] - mean, 2);
	}

	variance /= n;
	stdDeviation = sqrt(variance);

	printf("Standard Deviation: %.2f\n", stdDeviation);
}