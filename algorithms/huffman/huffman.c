#include <stdio.h>
#include "tree.h"
#include "queue.h"

#define MAX_CODE_LENGTH 256

void print_code(int *c, int n)
{
  for (int i = 0; i < n; i++) {
    printf("%i", c[i]);
  }
  printf("\n");
}

void print_huffman(tree_t *t, int *c, int i)
{
  if (t == NULL) {
    return;
  }

  if (t->ch == 0) {
    c[i] = 0;
    print_huffman(t->left, c, i + 1);
    c[i] = 1;
    print_huffman(t->right, c, i + 1);
  } else {
    printf("%c: ", t->ch);
    print_code(c, i);
  }
}

void huffman(const char *s)
{
  int freq[256] = {};
  tree_t *t, *a, *b;

  for (int i = 0; s[i] != '\0'; i++) {
    freq[s[i]]++;
  }

  queue_t *q = queue_init(256);

  for (int i = 0; i < 256; i++) {
    if (freq[i] > 0) {
      t = tree_init(i, freq[i], NULL, NULL);
      queue_enqueue(q, t, t->freq);
    }
  }

  while (queue_length(q) > 1) {
    a = queue_dequeue(q);
    b = queue_dequeue(q);

    t = tree_init(0, a->freq + b->freq, a, b);
    queue_enqueue(q, t, t->freq);
  }

  t = queue_dequeue(q);
  int c[MAX_CODE_LENGTH] = {};
  print_huffman(t, c, 0);
}

int main(void)
{
  huffman("qwerty");
  return 0;
}

