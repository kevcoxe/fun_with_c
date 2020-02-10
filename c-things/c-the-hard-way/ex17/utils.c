#include <stdio.h>

#include "consts.h"
#include "utils.h"


int prompt_confirm() {
  int return_val = 0;
  char command[MAX_DATA] = { ' ' };

  prompt_string("Are you sure (y/n): ", command);

  switch (command[0]) {
    case 'y':
      return_val = 1;
      break;

    case 'Y':
      return_val = 1;
      break;

    case 'n':
      return_val = 0;
      break;

    case 'N':
      return_val = 0;
      break;

    default:
      break;
  }

  return return_val;
}


void prompt_string(char *prompt_text, char *input) {

  printf("%s: ", prompt_text);
  scanf("%s", input);

  return;
}


void prompt_int(char *prompt_text, int *input) {

  printf("%s: ", prompt_text);
  scanf("%d", input);

  return;
}


void print_break_line(int num_new_lines) {
  printf("-------------------------------------------------------------------------------------------------------");
  for (int i = 0; i < num_new_lines; i++) {
    printf("\n");
  }
}


void print_string(char *s) {

  for (int i = 0; s[i] != '\0'; i++) {
    printf("%d -> %c\n", i, s[i]);
  }

  return;
}
