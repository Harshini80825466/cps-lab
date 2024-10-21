#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{	int t;
	float variance;
	double number;
	FILE* in_file = fopen("scores-data.txt", "r");
	if (! in_file )
	{
		printf("oops, file can't be read\n");
		exit(-1);
	}

	int arr[30];
	int n=0;
	float sum =0;
	while ( fscanf(in_file, "%lf", & number ) == 1 )
	{
		arr[n]= number;
		sum += number;
		n++;
		/*printf("We just read %lf\n", number);*/
	}

	printf("Array length %d\n", n);


	float mean=0;
	mean  = sum/n;
	printf("mean %f\n", mean);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i]<arr[j])
			{
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
		}
	}

	float median;
	if(n%2==0)

		median=( (arr[(n-1)/2] + arr[(n-1)/2+1] ) / 2.0);

	else

		median=( (arr[(n)/2]) );


	printf("median is %.1f\n",median);



	int mode;
	int c =0;
	int max;

	for(int i=0; i<n; i++)

	{

		t=arr[i];

		c=0;

		for(int j=0; j<n; j++) {
			if(t==arr[j]) c++;
			if(c>max)

			{

				max=c;

				mode=t;

			}

		}

	}

	printf("mode is %d\n",mode);


	float stdDeviation;
	for (int i = 0; i < n; i++) {
		variance += pow(arr[i] - mean, 2);
	}

	variance /= n;
	stdDeviation = sqrt(variance);

	printf("Standard Deviation: %.2f\n", stdDeviation);
}

