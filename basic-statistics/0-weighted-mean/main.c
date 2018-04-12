#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i = 0, n = 0, divisor = 0, dividendo = 0;
    scanf("%d", &n);

    int* x = malloc(n * sizeof(int));
    int* y = malloc(n * sizeof(int));

    if(x != NULL)
		for(i = 0; i < n; i++)
			scanf("%i", &x[i]);

    if(y != NULL)
		for(i = 0; i < n; i++)
            scanf("%i", &y[i]);

    for(i = 0; i < n; i++)
		divisor += y[i];

	if(divisor != 0)
        for(i = 0; i < n; i++)
            dividendo += (x[i] * y[i]);

	printf("%.1f\n", (double) dividendo / divisor);
    free(x);
    free(y);
    return 0;
}
