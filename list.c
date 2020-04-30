#include "list.h"
#include <stdlib.h>

Node *create_node(value)
{
  Node *node = malloc(sizeof(Node));
  if (node != NULL)
  {
    node->value = value;
    node->next = NULL;
  }
  return node;
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  if (list != NULL)
  {
    list->head = NULL;
    list->last = NULL;
    list->count = 0;
  }
  return list;
}

Status add_to_start(List_ptr list, int value)
{
  Node *element = create_node(value);
  if (element != NULL)
  {
    element->next = list->head;
    list->head = element;
    list->count += 1;
    return Success;
  }
  return Failure;
}