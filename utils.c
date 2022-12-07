#include "utils.h"
#include <ctype.h>
#include <stdio.h>

void resize(stack *s) {
  if (s->size >= s->capacity) {
    s->capacity *= 2;
    s->ptr = realloc(s->ptr, s->capacity);
  } else if (s->size <= s->capacity / 2 && s->size >= 8) {
    s->capacity /= 2;
    s->ptr = realloc(s->ptr, s->capacity);
  }
}

void pop(stack *s) {
  s->top--;
  s->size--;
  resize(s);
}

int getOpPrec(char op) {
  switch (op) {
  default:
    return 0;
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 10;
  case '^':
    return 20;
  case EOF:
    return -1;
  }
}

double computeBinOp(double lhs, double rhs, char op) {
  switch (op) {
  default:
    fprintf(stderr, "no such operator\n");
  case '*':
    return lhs * rhs;
  case '/':
    return lhs / rhs;
  case '+':
    return lhs + rhs;
  case '-':
    return lhs - rhs;
  case '^':
    return pow(lhs, rhs);
  }
}

