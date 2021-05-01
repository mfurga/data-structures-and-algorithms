#ifndef _TREE_H_INCLUDED_
#define _TREE_H_INCLUDED_

#include <stdlib.h>

typedef struct tree_s tree_t;

typedef struct tree_s {
  char      ch;
  int       freq;
  tree_t   *left;
  tree_t   *right;
} tree_t;

tree_t *tree_init(char ch, int freq, tree_t *left, tree_t *right)
{
  tree_t *t = (tree_t *)malloc(sizeof(tree_t));
  t->ch = ch;
  t->freq = freq;
  t->left = left;
  t->right = right;
  return t;
}

void tree_remove(tree_t *t)
{
  free(t);
}

#endif  // _TREE_H_INCLUDED_

