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
  Status status = insert_at(list, 20, 0);
  if (list->head->value == 20 && status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_insert_at_wrong_position()
{
  List_ptr list = create_list();
  Status status1 = insert_at(list, 10, 2);
  Status status2 = insert_at(list, 10, -2);
  if (list->count == 0 && !status1 && !status2)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_add_unique_if_exist()
{
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status status = add_unique(list, 10);
  if (list->count == 1 && !status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_add_unique_does_not_exist()
{
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status status = add_unique(list, 30);
  if (list->count == 2 && status)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_from_start_in_empty_list()
{
  List_ptr list = create_list();
  Status status = remove_from_start(list);
  if (!status && list->head == NULL && list->last == NULL && list->count == 0)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_from_start_in_list_with_one_number()
{
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status status = remove_from_start(list);
  if (status && list->head == NULL && list->last == NULL && list->count == 0)
  {
    return Pass;
  }
  return Fail;
}

test_status assert_remove_from_start()
{
  List_ptr list = create_list();
  add_to_end(list, 10);
  add_to_end(list, 20);
  add_to_end(list, 30);
  Status status = remove_from_start(list);
  if (status && list->head->value == 20 && list->last->value == 30 && list->count == 2)
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
  describe("add_to_start()");
  it("should add to the start of empty list", assert_add_to_start_in_empty_list());
  it("should add to the start of list", assert_add_to_start());
  describe("insert_at()");
  it("should insert_at given position in list", assert_insert_at());
  it("should not insert at invalid position", assert_insert_at_wrong_position());
  describe("add_unique()");
  it("should not add if number exist in list", assert_add_unique_if_exist());
  it("should add to end if number doesn't exist in list", assert_add_unique_does_not_exist());
  describe("remove from beginning of list");
  it("should not remove if list is empty", assert_remove_from_start_in_empty_list());
  it("should remove the only number of list if list has one element", assert_remove_from_start_in_list_with_one_number());
  it("should remove the first element of list with many elements", assert_remove_from_start());
  return 0;
}