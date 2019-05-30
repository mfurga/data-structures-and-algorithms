// Hash table using the open addressing approach (linear probing).
#include <stdlib.h>
#include <string.h>

#include "hash_table_open_addressing.h"

hash_table_t *create_hash_table(void)
{
  hash_table_t *ht = (hash_table_t *)malloc(sizeof(hash_table_t));
  if (ht == NULL)
    return NULL;
  ht->n = 0;
  ht->m = 8;
  ht->array = (hash_table_entry_t *)malloc(sizeof(hash_table_entry_t) * ht->m);
  if (ht->array == NULL)
    return NULL;

  for (int i = 0; i < ht->m; i++) {
    ht->array[i].key = NULL; ht->array[i].value = 0;
  }
  return ht;
}

static int hash(const char *key, const int m)
{
  int hash = 0;

  for (int i = 0; i < strlen(key); i++) {
    hash = hash * 29 + key[i];
  }
  return abs(hash % m);
}

void insert(hash_table_t *ht, const char *key, int value)
{
  if ((ht->n / (float)ht->m) > 0.6) {
    rehash(ht);
  }

  int h = hash(key, ht->m);
  while (ht->array[h].key != NULL && ht->array[h].key != deleted) {
    if (strcmp(ht->array[h].key, key) == 0) {
      ht->array[h].value = value;
      return;
    }
    h = (h + 1) % ht->m;
  }

  ht->array[h].key = strdup(key);
  ht->array[h].value = value;
  ht->n++;
}

int get(hash_table_t *ht, const char *key)
{
  int h = hash(key, ht->m);

  if (ht->array[h].key == NULL || ht->array[h].key == deleted)
    return -1;

  while (ht->array[h].key != NULL) {
    if (strcmp(ht->array[h].key, key) == 0)
      return ht->array[h].value;

    h = (h + 1) % ht->m;
  }
  return -1;
}

void delete(hash_table_t *ht, const char *key)
{
  int h = hash(key, ht->m);

  if (ht->array[h].key == NULL || ht->array[h].key == deleted)
    return;

  while (ht->array[h].key != NULL) {
    if (strcmp(ht->array[h].key, key) == 0) {
      free(ht->array[h].key);
      ht->array[h].key = deleted;
      ht->n--;
      return;
    }
    h = (h + 1) % ht->m;
  }
}

void rehash(hash_table_t *ht)
{
  hash_table_entry_t *array = (hash_table_entry_t *)malloc(sizeof(hash_table_entry_t) * ht->m * 2);
  if (array == NULL)
    return;

  for (int i = 0; i < ht->m * 2; i++) {
    array[i].key = NULL; array[i].value = 0;
  }

  int h;
  for (int i = 0; i < ht->m; i++) {
    if (ht->array[i].key != NULL && ht->array[i].key != deleted) {
      h = hash(ht->array[i].key, ht->m * 2);

      while (array[h].key != NULL) {
        h = (h + 1) % (ht->m * 2);
      }

      array[h].key = ht->array[i].key;
      array[h].value = ht->array[i].value;
    }
  }

  ht->m *= 2;
  free(ht->array);
  ht->array = array;
}
