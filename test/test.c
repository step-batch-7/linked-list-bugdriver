#include "../list.h"
#include "../list.c"
#include "test.h"

test_status assert_add_to_end_in_empty_list()
{
  List_ptr list = create_list();
  Status status = add_to_end(list, 10);
  if (list->head->value == list->last->value && status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_add_to_end()
{
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status status = add_to_end(list, 20);
  if (list->last->value == 20 && status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_add_to_start_in_empty_list()
{
  List_ptr list = create_list();
  Status status = add_to_start(list, 10);
  if (list->head->value == 10 && status)
  {
    return Pass;
  }
  return Fail;
}

int main(void)
{
  describe("add_to_end()");
  it("should add to the end of empty list", assert_add_to_end_in_empty_list());
  it("should add to the end of list", assert_add_to_end());
  describe("add to start of the list");
  it("should add to the start of empty list", assert_add_to_start_in_empty_list());
  return 0;
}