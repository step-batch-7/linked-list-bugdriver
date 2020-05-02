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
  printf("(d) add a unique item on the list at the end(if it alreay exists, do not insert)\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
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
  case 'd':
    number = get_input("Enter a number : ");
    status = add_unique(list, number);
    if (status == Success)
    {
      printf("%d is added to the end of the list\n\n", number);
    }
    break;
  case 'e':
    status = remove_from_start(list);
    if (status == Success)
    {
      printf("first element is removed from list\n\n");
    }
    break;
  case 'f':
    status = remove_from_end(list);
    if (status == Success)
    {
      printf("last element is removed from list\n\n");
    }
    break;
  case 'g':
    position = get_input("Enter position : ");
    status = remove_at(list,position);
    if (status == Success)
    {
      printf("element is removed from %d position of the list\n\n", position);
    }
    break;
  case 'h':
    number = get_input("Enter a number : ");
    status = remove_first_occurrence(list, number);
    if (status == Success)
    {
      printf("first occurence of %d is removed from list\n\n", number);
    }
    break;
  case 'i':
    number = get_input("Enter a number : ");
    status = remove_all_occurrences(list, number);
    if (status == Success)
    {
      printf("all occurence of %d is removed from list\n\n", number);
    }
    break;
  case 'j':
    status = clear_list(list);
    if (status == Success)
    {
      printf("list is clear\n\n");
    }
    break;
  case 'k':
    number = get_input("Enter a number : ");
    position = index_of(list, number);
    if (position != -1)
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