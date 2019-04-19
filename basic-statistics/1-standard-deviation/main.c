#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  double sum = 0.0, mean = 0.0;
  // get number of items of array
  int n = 0;
  scanf("%d", &n);
  // get items for array
  int* x = malloc(n * sizeof(int));
  for(int i = 0; i < n; i++) {
    scanf("%i", &x[i]);
    // once read an item, set sum for mean
    sum += x[i];
  }
  // set mean
  mean = (double) sum / n;
  sum = 0.0;

  for(int i = 0; i < n; i++)
    sum += pow(x[i] - mean, 2);

  printf("%.1f", sqrt(sum/n));
    return 0;
}
