#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
	system("cls");

	double x;
	unsigned int n = 0;

	printf("x: ");
	scanf("%lf", &x);

	while (n < 1) {
		printf("n: ");
		scanf("%u", &n);
	}

	clock_t begin = clock();

	double recursiveFunc(double x, double F, unsigned int i)
	{	
		F = i == 0 ? x : F * ((x * x) / (4 * i * i + 2 * i));
		i++;
		return i < n ? F + recursiveFunc(x, F, i) : F;
	}

	double sumF = recursiveFunc(x, 0, 0);

	printf("sumF = %.15lf\n", sumF);
	printf("Delta: %.15lf\n", fabs((double)(sinh(x) - sumF)));


	clock_t end = clock();
	printf("Elapsed: %lf seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}		