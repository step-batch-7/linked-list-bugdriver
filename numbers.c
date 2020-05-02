#include <stdio.h>
#include "list.h"

int get_input(char *input_text)
{
  int number;
  printf("%s", input_text);
  scanf("%d", &number);
  return number;
}

int read_value(){
  return get_input("Enter number : ");
}

int read_position(){
  return get_input("Enter position : ");
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

Status perform_operation(List_ptr list, char option)
{
  int number,position;
  Status status;
  switch (option)
  {
  case 'a':
    status = add_to_end(list, read_value());
    break;
  case 'b':
    status = add_to_start(list, read_value());
    break;
  case 'c':
    status = insert_at(list, read_value(),read_position());
    break;
  case 'd':
    status = add_unique(list, read_value());
    break;
  case 'e':
    status = remove_from_start(list);
    break;
  case 'f':
    status = remove_from_end(list);
    break;
  case 'g':
    status = remove_at(list,read_position());
    break;
  case 'h':
    status = remove_first_occurrence(list, read_value());
    break;
  case 'i':
    status = remove_all_occurrences(list, read_value());
    break;
  case 'j':
    status = clear_list(list);
    break;
  case 'k':
    position = index_of(list, read_value());
    status = Success;
    if(position == -1)
      status = Failure;
    break;
  case 'l':
    display(list);
    printf("\n");
    status = Success;
    break;
  default:
    printf("wrong option!\n");
    status = Failure;
    break;
  }
  return status;
}

int main(void)
{
  char selected_option = ask_option();
  List_ptr list = create_list();

  while (selected_option != 'm')
  {
    Status status = perform_operation(list, selected_option);
    if(status == Success){
      printf("operation Succesfull\n\n");
    }
    if(status == Failure){
      printf("operation Failed\n\n");
    }
    fflush(stdin);
    selected_option = ask_option();
  }
  destroy_list(list);
  return 0;
}