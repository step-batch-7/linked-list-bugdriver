#include <stdio.h>
#include "test.h"

int desc_counter = 1;

void describe(String statement)
{
  printf("%d. %s\n", desc_counter, statement);
  desc_counter++;
}

void it(String statement, test_status status)
{
  if (status)
  {
    printf(SUCCESS_SYMBOL);
  }
  else
  {
    printf(FAILURE_SYMBOL);
  }
  printf("%s\n", statement);
}