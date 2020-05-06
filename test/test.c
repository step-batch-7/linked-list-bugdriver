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

test_status assert_add_to_start()
{
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status status = add_to_start(list, 20);
  if (list->head->value == 20 && list->head != list->last && status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_insert_at()
{
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status s = insert_at(list, 20, 0);
  if (list->head->value == 20 && s)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_insert_at_wrong_position()
{
  List_ptr list = create_list();
  Status s1 = insert_at(list, 10, 2);
  Status s2 = insert_at(list, 10, -2);
  if (list->count == 0 && !s1 && !s2)
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
  it("should add to the start of list", assert_add_to_start());
  describe("insert at given position in the list");
  it("should insert_at given position in list", assert_insert_at());
  it("should not insert at invalid position", assert_insert_at_wrong_position());
  return 0;
}