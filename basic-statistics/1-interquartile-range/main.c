#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void quickSort(int* x, int min, int max){
	int mid, hi, lo, i;

	if(min >= max)
		return;

	struct timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec);

	i = min + (double) (rand() / ((double) RAND_MAX + 1) * (max - min + 1));
	mid = x[i];
	x[i] = x[min];
	lo = min;
	hi = max;

	while(1){
		while(x[hi] >= mid){
			hi--;
			if (hi <= lo) break;
		}

		if(hi <= lo) {
			x[lo] = mid;
			break;
		}

		x[lo] = x[hi];
		lo++;
		while(x[lo] < mid){
			lo++;
			if(lo >= hi) break;
		}

		if(lo >= hi){
			lo = hi;
			x[hi] = mid;
			break;
		}

		x[hi] = x[lo];
	}
	quickSort(x, min, lo - 1);
	quickSort(x, lo + 1, max);
}

int median(int i, int f, int x[]){
	if ((f - i) <= 0)
		exit(-1);
	else {
		int result = 0, n = f - i, j = 0;
		int *y = malloc(n * sizeof(int));
		for(int a = i; a < f; a++) y[j++] = x[a];
		result = n % 2 == 0 ? ((y[(n-1)/2] + y[n/2]) / 2) : y[n/2];
		free(y);
		return result;
	}
}

int main() {
    // get how many integers to read
    int n = 0, e = 0, el = 0;
    scanf("%d", &n);
	// get n integers
    int* x = malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) scanf("%i", &x[i]);
	// get frequencies for integers
    int* y = malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		scanf("%i", &y[i]);
	// get number of elements for dataset
		e += y[i];
	}
	// filling z with integers based on given frequency
	int* z = malloc(e * sizeof(int));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < y[i]; j++)
			z[el++] = x[i];

    free(x);
    free(y);
    quickSort(z, 0, el - 1);

    printf("%.1f\n",
		(double) median((el+1)/2, el , z) - median(0, el/2, z));

    free(z);
    return 0;
}
