#ifndef MERGE_SORT_H
#define MERGE_SORT_H

namespace mf
{

template <typename T=int>
static void merge(T arr[], T copy[], int lo, int mid, int hi);

template <typename T=int>
static void sort(T arr[], T copy[], int lo, int hi);

template <typename T=int>
void sort(T arr[], int size);

}  // namespace mf

#endif  // MERGE_SORT_H
