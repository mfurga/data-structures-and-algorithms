#ifndef MERGE_SORT_H
#define MERGE_SORT_H

namespace mf
{

template <class T=int>
class Mergesort
{
 private:
  void merge(T arr[], T copy[], int lo, int mid, int hi);
  void sort(T arr[], T copy[], int lo, int hi);

 public:
  Mergesort() {}
  ~Mergesort() {}

  void sort(T arr[], int size);
};

}  // namespace mf

#endif  // MERGE_SORT_H
