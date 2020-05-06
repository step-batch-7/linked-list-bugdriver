#ifndef __TEST_H
#define __TEST_H

#define SUCCESS_SYMBOL "    ✅  "
#define FAILURE_SYMBOL "    ❌ "

typedef enum
{
  Fail,
  Pass
} test_status;

typedef char *String;

void it(String statement, test_status status);
void describe(String statement);

#endif