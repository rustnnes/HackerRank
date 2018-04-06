#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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


double mean(int n, int *x){
    double sum = 0;
    for (int i = 0; i < n; i++)
		sum += x[i];
    return (double) sum/n;
}

double median(int n, int* x){
    return n % 2 == 0 ?  ( (double) (x[(n-1)/2] + x[n/2]) / 2) : x[n/2];
}

int mode(int n, int* x){
    int mC = 0, mV = INT_MAX, m = INT_MAX, a;

    for(int i = 0; i < n; ++i) {
		int c = 0;

		for(int j = 0; j < n; ++j)
			if(i != j)
				if(x[j] == x[i])
					++c;

		if(c == 0){
			if(x[i] < mV)
				mV = x[i];
        } else {
            if(c > mC){
				mV = x[i];
				mC = c;
			}
        }

	}

    return mV;
}

int main(){
    int n = 0;
    scanf("%d", &n);

    int* x = malloc(n * sizeof(int));
    if(x == NULL)
		exit(-1);
	else
		for(int i = 0; i < n; i++)
			scanf("%d", &x[i]);

    quickSort(x, 0, n - 1);

    fprintf(stdout, "%.1f\n%.1f\n%d\n", mean(n, x), median(n, x), mode(n, x));
    return 0;
}
