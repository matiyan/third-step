#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TEST_NUM 2
#define CLASS_NUM 20

double summation(double scores[], int n);
double average(double scores[], int n);
double variance(double scores[], int n);
double standard_deviation(double scores[], int n);
void output(double scores[], int n);
int comp(const void* a, const void* b);

int main()
{
	double scores[TEST_NUM][CLASS_NUM] = {
		{65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70},
		{44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84}
	};

	printf("About Science-test\n");
	output(scores[0], CLASS_NUM);

	printf("\nAbout English-test\n");
	output(scores[1], CLASS_NUM);
	
	return 0;
}

double summation(double scores[], int n)
{
	int i;
	double sum = 0.0;
	for(i = 0; i < n; i++)
	{
		sum += scores[i];
	}
	return sum;
}

double average(double scores[], int n)
{
	return (summation(scores, n) / n);
}

double variance(double scores[], int n)
{
	int i;
	double* diff = (double*)malloc(sizeof(double) * n);
	double ave = average(scores, n);
	double res;

	for(i = 0; i < n; i++)
	{
		diff[i] = (ave - scores[i]) * (ave - scores[i]);
	}

	res = (summation(diff, n) / n);
	free(diff);
	return res;
}

double standard_deviation(double scores[], int n)
{
	return sqrt(variance(scores, n));
}

void output(double scores[], int n)
{
	int i;
	printf("average:%.1f\n", average(scores, CLASS_NUM));
	printf("S-deviation:%.1f\n", standard_deviation(scores, CLASS_NUM));
	printf("summation:%.1f\n", summation(scores, CLASS_NUM));
	
	
	printf("sort:");
	qsort((void*)scores, n, sizeof(scores[0]), comp);
	for(i = 0; i < n-1; i++)
	{
		printf("%4.1f ", scores[i]);
	}
	printf("%4.1f\n", scores[n-1]);
}

int comp(const void* a, const void* b)
{
	double a_ = *((double*)a);
	double b_ = *((double*)b);

	if(a_ < b_)return -1;
	if(a_ > b_)return 1;
	return 0;
}
