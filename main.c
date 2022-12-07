#include "utils.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

stack *ops, *nums;
int numVal, curTok;

int gettok() {
  static char lastChar = ' ';
  while (isspace(lastChar)) {
    lastChar = getchar();
  }
  if (isdigit(lastChar)) {
    char temp[20];
    int i = 0;
    do {
      temp[i++] = lastChar;
      lastChar = getchar();
    } while (isdigit(lastChar) || lastChar == '.');
    temp[i] = 0;
    numVal = strtod(temp, NULL);
    return token_number;
  }
  char ret = lastChar;
  lastChar = getchar();
  return ret;
}

void calculate() {
  if (getOpPrec(curTok) > getOpPrec(*(((char *)ops->ptr) + ops->top))) {
    push(char, ops, curTok);
  } else {
    if (ops->size == 0) {
      return;
    }

    // compute
    int top = nums->top;
    double *ptr = (double *)nums->ptr + top;
    double lhs = *(ptr - 1), rhs = *ptr;
    char op = *(((char *)ops->ptr) + ops->top);

    pop(nums);
    pop(nums);
    pop(ops);

    push(double, nums, computeBinOp(lhs, rhs, op));
    calculate();
  }
}

int main() {
  init(char, ops, 4);
  init(double, nums, 4);

  do {
    curTok = gettok();
    if (curTok == token_number) {
      push(double, nums, numVal);
    } else {
      calculate();
    }
  } while (curTok != EOF);

  for (int i = 0; i < nums->size; ++i) {
    printf("%lf ", *(((double *)nums->ptr) + i));
  }
  printf("\n");
  for (int i = 0; i < ops->size; ++i) {
    printf("%c ", *(((char *)ops->ptr) + i));
  }
}
