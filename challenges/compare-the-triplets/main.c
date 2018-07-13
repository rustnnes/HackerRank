#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

/*
 * Complete the solve function below.
 */

/*
 * Please store the size of the integer array to be returned in result_count pointer. For example,
 * int a[3] = {1, 2, 3};
 *
 * *result_count = 3;
 *
 * return a;
 *
 */
int* solve(int a0, int a1, int a2, int b0, int b1, int b2, int* result_count) {
  int a = 0, b = 0;
  static int ar[2];
  if(a0 > b0) a++;
  if(a0 < b0) b++;
  if(a1 > b1) a++;
  if(a1 < b1) b++;
  if(a2 > b2) a++;
  if(a2 < b2) b++;
  *result_count = 2;

  ar[0] = a;
  ar[1] = b;

  return ar;
}

int main(){
  FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

  char** a0A1A2 = split_string(readline());

  char* a0_endptr;
  char* a0_str = a0A1A2[0];
  int a0 = strtol(a0_str, &a0_endptr, 10);

  if (a0_endptr == a0_str || *a0_endptr != '\0') { exit(EXIT_FAILURE); }

  char* a1_endptr;
  char* a1_str = a0A1A2[1];
  int a1 = strtol(a1_str, &a1_endptr, 10);

  if (a1_endptr == a1_str || *a1_endptr != '\0') { exit(EXIT_FAILURE); }

  char* a2_endptr;
  char* a2_str = a0A1A2[2];
  int a2 = strtol(a2_str, &a2_endptr, 10);

  if (a2_endptr == a2_str || *a2_endptr != '\0') { exit(EXIT_FAILURE); }

  char** b0B1B2 = split_string(readline());

  char* b0_endptr;
  char* b0_str = b0B1B2[0];
  int b0 = strtol(b0_str, &b0_endptr, 10);

  if (b0_endptr == b0_str || *b0_endptr != '\0') { exit(EXIT_FAILURE); }

  char* b1_endptr;
  char* b1_str = b0B1B2[1];
  int b1 = strtol(b1_str, &b1_endptr, 10);

  if (b1_endptr == b1_str || *b1_endptr != '\0') { exit(EXIT_FAILURE); }

  char* b2_endptr;
  char* b2_str = b0B1B2[2];
  int b2 = strtol(b2_str, &b2_endptr, 10);

  if (b2_endptr == b2_str || *b2_endptr != '\0') { exit(EXIT_FAILURE); }

  int result_count = 0;
  int* result = solve(a0, a1, a2, b0, b1, b2, &result_count);

  for (int result_itr = 0; result_itr < result_count; result_itr++) {
      fprintf(fptr, "%d", result[result_itr]);

      if (result_itr != result_count - 1)
          fprintf(fptr, " ");
  }
  fprintf(fptr, "\n");
  fclose(fptr);
  return 0;
}

char* readline() {
  size_t alloc_length = 1024;
  size_t data_length = 0;
  char* data = malloc(alloc_length);

  while (true) {
      char* cursor = data + data_length;
      char* line = fgets(cursor, alloc_length - data_length, stdin);

      if (!line) { break; }

      data_length += strlen(cursor);

      if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

      size_t new_length = alloc_length << 1;
      data = realloc(data, new_length);

      if (!data) { break; }

      alloc_length = new_length;
  }

  if (data[data_length - 1] == '\n')
      data[data_length - 1] = '\0';
  data = realloc(data, data_length);
  return data;
}

char** split_string(char* str) {
  char** splits = NULL;
  char* token = strtok(str, " ");

  int spaces = 0;

  while (token) {
      splits = realloc(splits, sizeof(char*) * ++spaces);
      if (!splits)
          return splits;
      splits[spaces - 1] = token;
      token = strtok(NULL, " ");
  }
  return splits;
}
