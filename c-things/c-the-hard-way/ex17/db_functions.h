#include <stdio.h>
#include "consts.h"

struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

struct Database {
  struct Address rows[MAX_ROWS];
};

struct Connection {
  FILE *file;
  struct Database *db;
};


void die(const char *);
void Address_print(struct Address *);
void Database_load(struct Connection *);
struct Connection *Database_open(const char *, char);
void Database_close(struct Connection *);
void Database_write(struct Connection *);
void Database_create(struct Connection *);
void Database_reset(struct Connection *);
void Database_set(struct Connection *, int, const char *, const char *);
void Database_get(struct Connection *, int);
void Database_delete(struct Connection *, int);
void Database_list(struct Connection *);
int Database_find_next_id(struct Connection *);
