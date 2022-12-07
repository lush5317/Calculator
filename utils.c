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

int gettok() {
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
  case '(':
    parseExpression();
    gettok();
    return getOpPrec(curTok);
  case ')':

  case EOF:
  case '\n':
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

void parseBinOp() {
  if (ops->size == 0 && getOpPrec(curTok) <= 0) {
    return;
  }
  if (getOpPrec(curTok) > getOpPrec(*(((char *)ops->ptr) + ops->top))) {
    push(char, ops, curTok);
  } else {
    // compute
    int top = nums->top;
    double *ptr = (double *)nums->ptr + top;
    double lhs = *(ptr - 1), rhs = *ptr;
    char op = *(((char *)ops->ptr) + ops->top);

    pop(nums);
    pop(nums);
    pop(ops);

    push(double, nums, computeBinOp(lhs, rhs, op));
    parseBinOp();
  }
}

void parseExpression() {
  do {
    curTok = gettok();
    if (curTok == token_number) {
      push(double, nums, numVal);
    } else {
      parseBinOp();
    }
  } while (lastChar != EOF && lastChar != '\n');
  parseBinOp();
}
