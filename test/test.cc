#include <cmath>
#include <cstdio>
#include <gtest/gtest.h>
extern "C" {
#include "../utils.c"
}

/** in test.in
 * 3.1+5.1
 * 3.1-5.1
 * 3.1*5.1
 * 3.1/5.1
 * 3.1^5.1
 * 5.1+(3.1+5.1)*3.1
 * 1.1+2.1-3.1*4.1/5.1^(6.1-7.1)+((9.1+1.1/8.1)*4.1)^2.1
 */

char lastChar = ' ';
int curTok;
double numVal;

TEST(ADD, simple_add) {
  double ret = parseExpression();
  ASSERT_DOUBLE_EQ(ret, 3.1 + 5.1);
}

TEST(MINUS, simple_minus) {
  double ret = parseExpression();
  ASSERT_DOUBLE_EQ(ret, 3.1 - 5.1);
}

TEST(MULT, simple_mult) {
  double ret = parseExpression();
  ASSERT_DOUBLE_EQ(ret, 3.1 * 5.1);
}

TEST(DIV, simple_div) {
  double ret = parseExpression();
  ASSERT_DOUBLE_EQ(ret, 3.1 / 5.1);
}

TEST(POW, simple_pow) {
  double ret = parseExpression();
  ASSERT_DOUBLE_EQ(ret, pow(3.1, 5.1));
}

TEST(PARENTHESIS, parenthesis) {
  double ret = parseExpression();
  ASSERT_DOUBLE_EQ(ret, 5.1 + (3.1 + 5.1) * 3.1);
}

TEST(GENERAL, general) {
  double ret = parseExpression();
  ASSERT_DOUBLE_EQ(ret, 1.1 + 2.1 - 3.1 * 4.1 / pow(5.1, (6.1 - 7.1)) +
                            pow(((9.1 + 1.1 / 8.1) * 4.1), 2.1));
}

int main() {
  testing::InitGoogleTest();
  freopen("test/test.in", "r", stdin);
  return RUN_ALL_TESTS();
}