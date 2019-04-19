#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>

/* Aux Fns
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n){
   int i, j;
   for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void sort_another_array(int *param, int *target, int size) {
    int i, j, past_min = INT_MAX, current_min = INT_MAX;
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            if (i == 0 || param[j] > past_min) {
                if (past_min == current_min || param[j] < current_min) {
                    current_min = param[j];
                }
            }
        }
        target[i] = current_min;
        past_min = current_min;
    }
}
*/

void sort_another_array(int *x, int *y, int n){
  int i, j, pMin = INT_MAX, cMin = INT_MAX;
  for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j)
          if (i == 0 || x[j] > pMin)
              if (pMin == cMin || x[j] < cMin)
				cMin = x[j];
      y[i] = cMin;
      pMin = cMin;
  }
}

void quickSort(int* x, int min, int max){
  int mid, hi, lo, i;

  if(min >= max)
    return;

  struct timeval t1;
  gettimeofday(&t1, NULL);
  srand(t1.tv_usec * t1.tv_sec);

  i = min + (double) (rand() / (double) (RAND_MAX + 1) * (max - min + 1));
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
  for (int i = 0; i < n; ++i)
	sum += x[i];
  return (double) (sum/n);
}

double median(int n, int* x){
  double result = 0;

    /*
    FILE *g;
    g = fopen("testcases/input/test.txt", "w");
	for (int i = 0; i < n; i++)
		fprintf(g, "%i\n", x[i]);
    fclose(g);

*/

  result = n % 2 == 0 ?  ( (double) (x[(n-1)/2] + x[n/2]) / 2) : x[n/2];
/*    double a = x[(n-1)/2];
    double b = (n-1)/2;
    double c = x[n/2];
    double d = n/2;
    double e = x[(n-1)/2] + x[n/2];
    double f = e / 2;

    printf("%.1f\t %.1f\n %.1f\t %.1f\n %.1f\t %.1f\n\n\n", a, b, c, d, e, f );*/
  return result;
}

int mode(int n, int* x){
  int mC = 0, mV = INT_MAX;

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

int getN(FILE* f){
  size_t n = 0;
  int c;
  char *code = malloc(2);

  while ((c = fgetc(f)) != EOF){
    if(c == '\n'){
      code[n] = '\0';
      break;
    } else
      code[n++] = (char) c;
  }

  //int cnv = atoi(code);
  //printf("%d\n", cnv);
  return atoi(code); //cnv;
}

int getItem(FILE* f){
  long n = 0;
  int c;
  char *code = malloc(1000);

  while ((c = fgetc(f)) != EOF){
    if(c == ' ' || c == '\n'){
      code[n] = '\0';
      //int cnv = atoi(code);
      //printf("%d\n", cnv);
      return atoi(code); //cnv;
    } else
      code[n++] = (char) c;
  }
  return NULL;
}

int main(){
  FILE *f;
  f = fopen("testcases/input/input04.txt", "r");
  if(f == NULL) exit (-1);

  int n = getN(f);
  printf("%d\n", n);
  //scanf("%d", &n);

  int i = 0, item;
  int* x = malloc(n * sizeof(int));
  if(x == NULL)
    exit(-1);
  else
    while ( (item = getItem(f)) != NULL)
      x[i++] = item;

  quickSort(x, 0, n-1);

  fprintf(stdout, "%.1f\n%.1f\n%d\n", mean(n, x), median(n, x), mode(n, x));
  return 0;
}
