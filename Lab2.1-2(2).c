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

	double sumF = 0;
	double recursiveFunc(double x, unsigned int i)
	{	
		double F;
		if (i == 0)
		{
			F = x;
		} else {
			double m = (x * x) / (4 * i * i + 2 * i);
			F = m * recursiveFunc(x, i - 1);
		}
		sumF += F;
		return F;
	}

	double F = recursiveFunc(x, n);
	// double sumF = recursiveFunc(x, 0, 0, 0, 0);

	printf("sumF = %.15lf\n", sumF);
	printf("Delta: %.15lf\n", fabs((double)(sinh(x) - sumF)));


	clock_t end = clock();
	printf("Elapsed: %lf seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}		