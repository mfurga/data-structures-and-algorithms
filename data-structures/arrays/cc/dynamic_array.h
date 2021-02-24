#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <memory>
#include <optional>

namespace mf
{

class DynamicArray
{
 private:
  int size;
  int capacity;
  std::unique_ptr<int[]> array;

  // Resize the capacity of the array (2x).
  void resize();

 public:
  // Constructor & destructor
  DynamicArray();
  ~DynamicArray();

  // Return the size of the array.
  int get_size() const;

  // Check if the array is empty.
  bool is_empty() const;

  // Return the capacity of the array.
  int get_capacity() const;

  // Add an item to the end of the array.
  void push_back(int value);

  // Remove the item at the end of the array, and return it.
  std::optional<int> pop_back();

  // Update the item at the given position in the array.
  void update(int index, int value);

  // Get the item at the given position.
  std::optional<int> get(int index) const;

  // Insert the new item in the given position.
  void insert(int index, int value);

  // Delete the item from the given position.
  void remove(int index);

  // Return the index of the first item.
  std::optional<int> find(int value) const;
};

}  // namespace mf

#endif  // DYNAMIC_ARRAY_H
