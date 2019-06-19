#ifndef QUICK_SORT_H
#define QUICK_SORT_H

namespace mf
{

template<typename T>
static int partition(T *arr, int lo, int hi);

template<typename T>
static void quicksort(T *arr, int lo, int hi);

template<typename T=int>
void quicksort(T *arr, int size);

}  // namespace mf

#endif  // QUICK_SORT_H
