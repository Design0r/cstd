#include <assert.h>
#define DA_INIT_CAP 2
#include "array.h"
#include <stdio.h>

typedef struct {
  int *items;
  size_t length;
  size_t capacity;
} IntArray;

int main() {
  IntArray a = {0};

  for (size_t i = 0; i < 10; i++) {
    da_append(&a, i);
  }

  assert(a.length == 10);
  int val = da_pop(&a);
  assert(a.length == 9);
  printf("%d\n", val);

  da_free(a);

  printf("len: %zu, cap: %zu\n", a.length, a.capacity);

  return 0;
}
