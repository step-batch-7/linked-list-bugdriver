#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *create_node(value)
{
  Node *node = malloc(sizeof(Node));
  if (node == NULL)
    return node;
  node->value = value;
  node->next = NULL;
  return node;
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  if (list == NULL)
    return list;
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_start(List_ptr list, int value)
{
  Node *element = create_node(value);
  if (element == NULL)
    return Failure;
  element->next = list->head;
  list->head = element;
  list->count += 1;
  return Success;
}

Status add_to_end(List_ptr list, int value)
{
  Node *element = create_node(value);
  if (element == NULL)
    return Failure;
  if (list->head == NULL)
  {
    list->head = element;
  }
  else
  {
    list->last->next = element;
  }
  list->last = element;
  list->count += 1;
  return Success;
}

void display(List_ptr list)
{
  Node *p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d\n", p_walk->value);
    p_walk = p_walk->next;
  }
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position < 0 || position > list->count + 1)
    return Failure;

  if (position == 0)
    return add_to_start(list, value);

  Node *element = create_node(value);
  Node *p_walk = list->head;
  for (int index = 0; index < position - 1; index++)
  {
    p_walk = p_walk->next;
  }
  element->next = p_walk->next;
  p_walk->next = element;
  list->count += 1;
  return Success;
}

int index_of(List_ptr list, int value)
{
  Node *p_walk = list->head;
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
  if (list->head == NULL)
  {
    return Failure;
  }
  Node *element_to_remove = list->head;
  list->head = list->head->next;
  free(element_to_remove);
  list->count -= 1;
  return Success;
}

Status remove_from_end(List_ptr list)
{
  Node *p_walk = list->head;
  if (p_walk == NULL)
  {
    return Failure;
  }
  if (p_walk->next == NULL)
  {
    return remove_from_start(list);
  }
  while (p_walk->next->next != NULL)
  {
    p_walk = p_walk->next;
  }
  Node *element_to_remove = p_walk->next;
  p_walk->next = NULL;
  free(element_to_remove);
  list->count -= 1;
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if (position < 0 || position > list->count)
    return Failure;
  if (position == 0)
    return remove_from_start(list);
  Node *p_walk = list->head;
  for (int index = 0; index < position - 1; index++)
  {
    p_walk = p_walk->next;
  }
  Node *element_to_remove = p_walk->next;
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