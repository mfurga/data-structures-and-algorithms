// Hash table using the open addressing approach (linear probing).
#ifndef HASH_TABLE_OPEN_ADDRESSING_H
#define HASH_TABLE_OPEN_ADDRESSING_H

static char *deleted = "0";

typedef struct {
  char *key;
  int value;
} hash_table_entry_t;

typedef struct hash_table {
  int n;  // number of entries occupied in the hash table
  int m;  // number of slots in the hash table
  hash_table_entry_t *array;
} hash_table_t;

hash_table_t *create_hash_table(void);

void insert(hash_table_t *ht, const char *key, int value);

int get(hash_table_t *ht, const char *key);

void delete(hash_table_t *ht, const char *key);

void rehash(hash_table_t *ht);

static int hash(const char *key, const int m);

#endif  // HASH_TABLE_OPEN_ADDRESSING_H