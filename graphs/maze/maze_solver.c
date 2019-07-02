/*
  The maze solver app.
  The maze based on: https://eduinf.waw.pl/inf/alg/001_search/0128.php.

  Copyright 2019 Mateusz Furga <matfurga@gmail.com>
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#ifdef WIN32
  #include <windows.h>  /* Used for a path highlighting. */
#endif

typedef struct
{
  unsigned int col;
  unsigned int row;
} cord_t;

typedef struct
{
  int capacity;
  int read;
  int write;
  cord_t *array;
} queue_t;

/* Queue implementation. */

queue_t *create_queue(int capacity);

void remove_queue(queue_t *queue);

bool empty_queue(queue_t *queue);

void enqueue(queue_t *queue, cord_t coordinates);

cord_t dequeue(queue_t *queue);

bool solve(char **maze, int rows, int cols, cord_t start, cord_t end);

void print_maze(char **maze, int rows, int cols);

int main(int argc, char **argv)
{
  FILE *f;
  char *buffer;
  char **maze;
  cord_t start, end;
  bool verbose = false;
  int opt, rows = 0, cols = 0;

  while ((opt = getopt(argc, argv, "r:c:vh")) != -1) {
    switch (opt) {
      case 'v':
        verbose = true;
      break;
      case 'r':
        rows = atoi(optarg);
      break;
      case 'c':
        cols = atoi(optarg);
      break;
      case 'h':
        printf("Usage: %s [-r ROWS] [-c COLUMNS] [-v] [file...]\n", argv[0]);
        return 0;
      break;
      default:
        fprintf(stderr, "Usage: %s [-r ROWS] [-c COLUMNS] [-v] [file...]\n", argv[0]);
        return 1;
    }
  }

  if (rows == 0 || cols == 0) {
    fprintf(stderr, "ERROR: -r & -c are required.\n");
    return 1;
  }

  if ((f = fopen(argv[optind], "r")) == NULL) {
    fprintf(stderr, "Unable to open the file %s.\n", argv[optind]);
    return 1;
  }

  fseek(f, 0, SEEK_END);
  size_t sz = ftell(f);
  fseek(f, 0, SEEK_SET);

  if ((buffer = (char *)malloc(sizeof(char) * sz)) == NULL) {
    fprintf(stderr, "Unable to allocate a memory for the file.\n");
    return 2;
  }
  fread(buffer, sizeof(char), sz, f);
  fclose(f);

  if ((maze = (char **)malloc(sizeof(char *) * rows)) == NULL) {
    fprintf(stderr, "Unable to allocate a memory for the maze.\n");
    return 3;
  }

  for (int i = 0; i < rows; i++) {
    if ((maze[i] = (char *)malloc(sizeof(char) * cols)) == NULL) {
      fprintf(stderr, "Unable to allocate a memory for the maze.\n");
      return 4;
    }
  }

  for (size_t i = 0, j = 0; i < sz; i++) {
    switch (buffer[i]) {
      case '\n':
        continue;
      break;
      case 'S':
        start.col = j % cols; start.row = j / cols;
      break;
      case 'E':
        end.col = j % cols; end.row = j / cols;
        buffer[i] = '.';
      break;
    }
    maze[j / cols][j % cols] = buffer[i];
    j++;
  }
  free(buffer);

  if (verbose)
    print_maze(maze, rows, cols);

  if (solve(maze, rows, cols, start, end) == false) {
    fprintf(stderr, "The maze cannot be solved.\n");
    return 5;
  }

  print_maze(maze, rows, cols);
  return 0;
}

/* Queue implementation. */

queue_t *create_queue(int capacity)
{
  queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
  if (queue == NULL)
    return NULL;
  queue->capacity = capacity + 1;
  queue->read = 0;
  queue->write = 0;
  queue->array = (cord_t *)malloc(sizeof(cord_t) * queue->capacity);
  if (queue->array == NULL)
    return NULL;
  return queue;
}

void remove_queue(queue_t *queue)
{
  if (queue == NULL || queue->array == NULL)
    return;
  free(queue->array);
  free(queue);
}

bool empty_queue(queue_t *queue)
{
  return queue->write == queue->read;
}

void enqueue(queue_t *queue, cord_t coordinates)
{
  if ((queue->write + 1) % queue->capacity == queue->read)
    return;  // The queue is full.

  queue->array[queue->write] = coordinates;
  queue->write = (queue->write + 1) % queue->capacity;
}

cord_t dequeue(queue_t *queue)
{
  cord_t res = queue->array[queue->read];
  queue->read = (queue->read + 1) % queue->capacity;
  return res;
}

bool solve(char **maze, int rows, int cols, cord_t start, cord_t end)
{
  queue_t *q = create_queue(rows * cols);
  cord_t cur, to_save;

  enqueue(q, start);
  while (!empty_queue(q)) {
    cur = dequeue(q);

    /* Check if we're done. */
    if (cur.row == end.row && cur.col == end.col) 
      break;

    /* Up. */
    to_save = cur;
    if (maze[cur.row - 1][cur.col + 0] == '.') {
      maze[cur.row - 1][cur.col + 0] = 'd';
      to_save.row -= 1;
      enqueue(q, to_save);
    }

    /* Down. */
    to_save = cur;
    if (maze[cur.row + 1][cur.col + 0] == '.') {
      maze[cur.row + 1][cur.col + 0] = 'u';
      to_save.row += 1;
      enqueue(q, to_save);
    }

    /* Right. */
    to_save = cur;
    if (maze[cur.row + 0][cur.col - 1] == '.') {
      maze[cur.row + 0][cur.col - 1] = 'r';
      to_save.col -= 1;
      enqueue(q, to_save);
    }

    /* Left. */
    to_save = cur;
    if (maze[cur.row + 0][cur.col + 1] == '.') {
      maze[cur.row + 0][cur.col + 1] = 'l';
      to_save.col += 1;
      enqueue(q, to_save);
    }
  }

  /* Check if the maze has been solved. */
  if (cur.row != end.row || cur.col != end.col)
    return false;

  cur = end;
  char c;
  while (cur.row != start.row || cur.col != start.col) {
    c = maze[cur.row][cur.col];
    maze[cur.row][cur.col] = '+';
    switch (c) {
      case 'd': cur.row++; break;
      case 'u': cur.row--; break;
      case 'r': cur.col++; break;
      case 'l': cur.col--; break;
    }
  }
  maze[end.row][end.col] = 'E';

  /* Clear the maze. */
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      switch (maze[i][j]) {
        case 'u': case 'd': case 'r': case 'l': case '.':
        maze[i][j] = ' ';
      }
    }
  }

  remove_queue(q);
  return true;
}

#ifdef WIN32
void print_path(const char *text, ...)
{
  va_list arg;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(hConsole, 10);
  va_start(arg, text);
  vfprintf(stdout, text, arg);
  va_end(arg);
  SetConsoleTextAttribute(hConsole, 7);
}
#else
void print_path(const char *text, ...)
{
  va_list arg;
  va_start(arg, text);
  vfprintf(stdout, text, arg);
  va_end(arg);
}
#endif

void print_maze(char **maze, int rows, int cols)
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (maze[i][j] == '+')
        print_path("%c", maze[i][j]);
      else
        printf("%c", maze[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
