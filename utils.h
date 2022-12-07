#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum token {
  token_number = 0,
  token_operator = 1,
};

typedef struct stack {
  void *ptr;
  int size;
  int capacity;
  int top;
} stack;

#define init(T, s, c)                                                          \
  do {                                                                         \
    s = (stack *)malloc(sizeof(stack));                                        \
    s->size = 0;                                                               \
    s->capacity = c;                                                           \
    s->ptr = (T *)malloc(c * sizeof(T));                                       \
    s->top = -1;                                                               \
  } while (0)

#define push(T, s, v)                                                          \
  do {                                                                         \
    T *ptr = (T *)s->ptr;                                                      \
    ptr[++s->top] = v;                                                         \
    s->size++;                                                                 \
    resize(s);                                                                 \
  } while (0)

void resize(stack *s);
void pop(stack *s);

int gettok();
void parseBinOp(stack *ops, stack *nums);
double parseExpression();
int getOpPrec(char op);
double computeBinOp(double lhs, double rhs, char op);

extern double numVal;
extern int curTok;
extern char lastChar;

#endif