#ifndef MERGE_SORT_H
#define MERGE_SORT_H

static void merge(int *arr, int *copy, int lo, int mid, int hi);

static void sort_(int *arr, int *copy, int lo, int hi);

void sort(int *arr, int size);

#endif  // MERGE_SORT_H
