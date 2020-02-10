
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "consts.h"
#include "utils.h"
#include "db_functions.h"


void die(const char *message) {
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

void Address_print(struct Address *addr) {
  printf("%-3d %-50s %-50s\n", addr->id, addr->name, addr->email);
  return;
}

void Database_load(struct Connection *conn) {
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
    die("Failed to load database");

  return;
}

struct Connection *Database_open(const char *filename, char mode) {
  struct Connection *conn = malloc(sizeof(struct Connection));
  if (!conn)
    die("Memmory error");

  conn->db = malloc(sizeof(struct Database));
  if (!conn->db)
    die("Memory error");

  if (mode == 'c') {
    conn->file = fopen(filename, "w");
  } else {
    conn->file = fopen(filename, "r+");

    if (conn->file) {
      Database_load(conn);
    }
  }

  if (!conn->file)
    die("Failed to open the file");

  return conn;
}

void Database_close(struct Connection *conn) {
  if (conn) {
    if (conn->file)
      fclose(conn->file);
    if (conn->db)
      free(conn->db);
    free(conn);
  }

  return;
}

void Database_write(struct Connection *conn) {
  rewind(conn->file);

  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
    die("Failed to write database");

  rc = fflush(conn->file);
  if (rc == -1)
    die("Cannot flush database");

  return;
}

void Database_create(struct Connection *conn) {
  for (int i = 0; i < MAX_ROWS; i++) {
    // make a prototype to initialize it
    struct Address addr = {.id = i,.set = 0};

    // then just assign it
    conn->db->rows[i] = addr;
  }

  return;
}

void Database_reset(struct Connection *conn) {
  for (int i = 0; i < MAX_ROWS; i++) {
    // make a prototype to initialize it
    struct Address addr = {.id = i,.set = 0};

    // then just assign it
    conn->db->rows[i] = addr;
  }

  return;
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email) {
  struct Address *addr = &conn->db->rows[id];
  if (addr->set)
    Database_delete(conn, id);

  addr->set = 1;
  // WARNING: bug, read the "How to Break It" and fix this
  char *res = strncpy(addr->name, name+'\0', MAX_DATA);

  // demonstrante the strncpy bug
  if (!res)
    die("Name copy failed");

  res = strncpy(addr->email, email, MAX_DATA);
  if (!res)
    die("Email copy failed");

  return;
}


void Database_get(struct Connection *conn, int id) {
  struct Address *addr = &conn->db->rows[id];

  if (addr->set) {
    Address_print(addr);
  } else {
    die("ID is not set");
  }

  return;
}

void Database_delete(struct Connection *conn, int id) {
  struct Address addr = {.id = id,.set = 0};
  conn->db->rows[id] = addr;

  return;
}

void Database_list(struct Connection *conn) {

  struct Database *db = conn->db;

  printf("%-3s %-50s %-50s\n", "ID", "NAME", "EMAIL");
  print_break_line(1);
  for (int i = 0; i < MAX_ROWS; i++) {
    struct Address *cur = &db->rows[i];

    if (cur->set) {
      Address_print(cur);
    }
  }

  return;
}

int Database_find_next_id(struct Connection *conn) {
  int open_id = -1;
  struct Database *db = conn->db;

  for (int i = 0; i < MAX_ROWS; i++) {
    struct Address *cur = &db->rows[i];

    if (!cur->set) {
      open_id = i;
      break;
    }
  }

  return open_id;
}

