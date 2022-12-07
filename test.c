#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  stack *s = malloc(sizeof(stack));
  init(int, s, 4);
  printf("%d\n", s->size);
  fflush(stdout);
  push(int, s, 4);
  push(int, s, 8);
  printf("capacity=%d,top=%d,ptr[0]=%d, topitem=%d\n", s->capacity, s->top,
         *(int *)s->ptr, *((int *)(s->ptr) + s->top));
}
