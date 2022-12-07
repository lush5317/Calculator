#include "utils.h"
#include <stdio.h>

double numVal;
int curTok;
char lastChar = ' ';

int main() {
  double ret = parseExpression();
  printf("%lf", ret);
}
