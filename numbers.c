#include <stdio.h>
#include "list.h"

int get_input(char *input_text)
{
  int number;
  printf("%s", input_text);
  scanf("%d", &number);
  return number;
}

char ask_option()
{
  char option;
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(k) check if a number exists in the list\n");
  printf("(m) exit\n");
  printf("\nPlease enter the alphabet of the operation you would like to perform\n");
  scanf("%c", &option);
  return option;
}

void perform_operation(List_ptr list, char option)
{
  int number,position;
  Status status;
  switch (option)
  {
  case 'a':
    number = get_input("Enter a number : ");
    status = add_to_end(list, number);
    if (status == Success)
    {
      printf("%d is added to the end of the list\n\n", number);
    }
    break;
  case 'b':
    number = get_input("Enter a number : ");
    status = add_to_start(list, number);
    if (status == Success)
    {
      printf("%d is added to the start of the list\n\n", number);
    }
    break;
  case 'c':
    number = get_input("Enter a number : ");
    position = get_input("Enter position : ");
    status = insert_at(list, number,position);
    if (status == Success)
    {
      printf("%d is inserted at given position in the list\n\n", number);
    }
    break;
  case 'k':
    number = get_input("Enter a number : ");
    status = includes(list, number);
    if (status == Success)
    {
      printf("%d is present in the list\n\n", number);
    }
    break;
  case 'l':
    display(list);
    printf("\n");
    break;
  default:
    printf("wrong option!\n");
    break;
  }
}

int main(void)
{
  char selected_option = ask_option();
  List_ptr list = create_list();

  while (selected_option != 'm')
  {
    perform_operation(list, selected_option);
    fflush(stdin);
    selected_option = ask_option();
  }
}