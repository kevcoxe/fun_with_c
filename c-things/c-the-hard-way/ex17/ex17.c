#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "db_functions.h"
#include "utils.h"
#include "ex17.h"

void prompt_and_add(struct Connection *conn) {
  printf("checking for an open id...\n");
  int open_id = Database_find_next_id(conn);

  // check if open id found
  if (open_id < 0) {
    printf("sorry database is full\n");
    return;
  }

  char name[MAX_DATA];
  prompt_string("please enter the name", name);

  char email[MAX_DATA];
  prompt_string("please enter the email", email);

  Database_set(conn, open_id, name, email);
  Database_write(conn);

  return;
}

void prompt_and_set(struct Connection *conn) {
  printf("Setting info:\n");

  int id;
  prompt_int("please enter the id", &id);

  char name[MAX_DATA];
  prompt_string("please enter the name", name);

  char email[MAX_DATA];
  prompt_string("please enter the email", email);

  Database_set(conn, id, name, email);
  Database_write(conn);

  return;
}


void prompt_and_get(struct Connection *conn) {
  int id;
  prompt_int("please enter the id", &id);
  Database_get(conn, id);

  return;
}


void prompt_and_delete(struct Connection *conn) {
  int id;
  prompt_int("please enter the id", &id);
  Database_delete(conn, id);

  return;
}


void prompt_and_reset(struct Connection *conn) {
  if (prompt_confirm()) {
    Database_reset(conn);
    Database_write(conn);
  }

  return;
}


void interactive_help() {

  printf("l=list s=set g=get d=delete\n");

  return;
}

void print_break_line(int num_new_lines) {
  printf("---------------------------------");
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


void interactive_prompt(struct Connection *conn) {

  char command[MAX_DATA] = { ' ' };

  do {
    interactive_help();
    prompt_string("enter command", command);

    switch (command[0]) {
      case 'a':
        prompt_and_add(conn);
        break;

      case 'l':
        print_break_line(1);
        Database_list(conn);
        break;

      case 's':
        prompt_and_set(conn);
        break;

      case 'g':
        prompt_and_get(conn);
        break;

      case 'd':
        prompt_and_delete(conn);
        break;

      case 'r':
        prompt_and_reset(conn);
        break;

      case 'q':
        break;

      default:
        printf("Invalid input");
        interactive_help();
    }

    print_break_line(2);

  } while (*command != 'q');

  return;
}


int main(int argc, char *argv[]) {

  if (argc < 3)
    die("USAGE: ext17 <dbfile> <action> [action params]");

  char *filename = argv[1];
  char action = argv[2][0];
  struct Connection *conn = Database_open(filename, action);
  int id = 0;

  if (argc > 3) id = atoi(argv[3]);
  if (id >= MAX_ROWS) die("There is not that many records");

  switch (action) {
    case 'c':
      Database_create(conn);
      Database_write(conn);
      break;

    case 'g':
      if (argc != 4)
        die("Need an id to get");

      Database_get(conn, id);
      break;

    case 's':
      if (argc != 6)
        die("Need id, name, email to set");

      Database_set(conn, id, argv[4], argv[5]);
      Database_write(conn);
      break;

    case 'a':
      if (argc != 5)
        die("Need name, email to set");

      int open_id = Database_find_next_id(conn);

      // check if open id found
      if (open_id < 0) {
        printf("sorry database is full\n");
        break;
      }

      Database_set(conn, open_id, argv[3], argv[4]);
      Database_write(conn);
      break;

    case 'd':
      if (argc != 4)
        die("Need id to delete");

      Database_delete(conn, id);
      Database_write(conn);
      break;

    case 'l':
      Database_list(conn);
      break;

    case 'i':
      interactive_prompt(conn);
      break;

    default:
      die("Invalid action: c=create, g=get, s=set, d=delete, l=list");
  }

  Database_close(conn);

  return 0;
}

