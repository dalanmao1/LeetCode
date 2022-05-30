#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void* _a, const void* _b) {
  int* a = (int*)_a;  //强制类型转换
  int* b = (int*)_b;
  return *a - *b;
}

int main(int argc, char const* argv[]) {
  int jobs[5] = {1, 2, 6, 5, 4};

  qsort(jobs, 5, sizeof(int), cmp_int);
  for (int i = 0; i < 5; i++) {
    printf("%d", jobs[i]);
  }

  return 0;
}
