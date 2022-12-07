#include "utils.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

stack *ops, *nums;
int numVal, curTok;
char lastChar = ' ';

int main() {
  init(char, ops, 4);
  init(double, nums, 4);

  parseExpression();

  for (int i = 0; i < nums->size; ++i) {
    printf("%lf ", *(((double *)nums->ptr) + i));
  }
  printf("\n");
  for (int i = 0; i < ops->size; ++i) {
    printf("%c ", *(((char *)ops->ptr) + i));
  }
}
