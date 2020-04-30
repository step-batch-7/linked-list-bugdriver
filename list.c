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