#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Status is_null(void *element)
{
  if (element == NULL)
  {
    return Success;
  }
  return Failure;
}

Node_ptr create_node(value)
{
  Node_ptr node = malloc(sizeof(Node));
  if (is_null(node))
  {
    return node;
  }
  node->value = value;
  node->next = NULL;
  return node;
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  if (is_null(list))
  {
    return list;
  }
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr element = create_node(value);
  if (is_null(list) || is_null(element))
  {
    return Failure;
  }
  element->next = list->head;
  list->head = element;
  list->count += 1;
  return Success;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr element = create_node(value);
  if (is_null(list) || is_null(element))
  {
    return Failure;
  }
  Node_ptr *ptr_to_set = &list->head;
  if (list->head != NULL)
  {
    ptr_to_set = &list->last->next;
  }
  (*ptr_to_set) = element;
  list->last = element;
  list->count += 1;
  return Success;
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d\n", p_walk->value);
    p_walk = p_walk->next;
  }
}

Status insert_at(List_ptr list, int value, int position)
{
  Node_ptr node = create_node(value);
  if (is_null(node) || is_null(list) || position < 0 || position >= list->count + 1)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, value);
  }
  Node_ptr p_walk = list->head;
  for (int index = 0; index < position - 1; index++)
  {
    p_walk = p_walk->next;
  }
  node->next = p_walk->next;
  p_walk->next = node;
  list->count += 1;
  return Success;
}

int index_of(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  for (int index = 0; p_walk != NULL; index++)
  {
    if (p_walk->value == value)
    {
      return index;
    }
    p_walk = p_walk->next;
  }
  return -1;
}

Status add_unique(List_ptr list, int value)
{
  if (index_of(list, value) == -1)
  {
    return add_to_end(list, value);
  }
  return Failure;
}

Status remove_from_start(List_ptr list)
{
  if (is_null(list) || is_null(list->head))
  {
    return Failure;
  }
  Node_ptr element_to_remove = list->head;
  list->head = list->head->next;
  if (list->head == NULL)
  {
    list->last = NULL;
  }
  free(element_to_remove);
  list->count -= 1;
  return Success;
}

Status remove_from_end(List_ptr list)
{
  Node_ptr p_walk = list->head;
  if (is_null(list) || is_null(p_walk))
  {
    return Failure;
  }
  if (is_null(p_walk->next))
  {
    return remove_from_start(list);
  }
  while (p_walk->next->next != NULL)
  {
    p_walk = p_walk->next;
  }
  Node_ptr element_to_remove = p_walk->next;
  p_walk->next = NULL;
  list->last = p_walk;
  free(element_to_remove);
  list->count -= 1;
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if (is_null(list) || position < 0 || position >= list->count)
  {
    return Failure;
  }
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position == list->count - 1)
  {
    return remove_from_end(list);
  }
  Node_ptr p_walk = list->head;
  for (int index = 0; index < position - 1; index++)
  {
    p_walk = p_walk->next;
  }
  Node_ptr element_to_remove = p_walk->next;
  p_walk->next = element_to_remove->next;
  free(element_to_remove);
  list->count -= 1;
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  int first_occured_position = index_of(list, value);
  if (first_occured_position != -1)
  {
    return remove_at(list, first_occured_position);
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  if (index_of(list, value) == -1)
  {
    return Failure;
  }
  while (remove_first_occurrence(list, value) != Failure)
    ;
  return Success;
}

Status clear_list(List_ptr list)
{
  if (is_null(list))
  {
    return Failure;
  }
  while (remove_from_start(list) != Failure)
    ;
  return Success;
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
}