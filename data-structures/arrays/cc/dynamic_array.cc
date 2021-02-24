#include <cstdio>
#include "dynamic_array.h"

namespace mf
{

DynamicArray::DynamicArray() : size(0), capacity(4)
{
  this->array = std::unique_ptr<int[]>(new int[this->capacity]);
}

DynamicArray::~DynamicArray() {}

int DynamicArray::get_size() const { return this->size; }

bool DynamicArray::is_empty() const { return this->size == 0; }

int DynamicArray::get_capacity() const { return this->capacity; }

void DynamicArray::push_back(int value)
{
  if (this->size >= this->capacity) {
    this->resize();
  }
  this->array[this->size++] = value;
}

std::optional<int> DynamicArray::pop_back()
{
  if (this->size == 0) {
    return std::nullopt;
  }
  return this->array[--this->size];
}

void DynamicArray::update(int index, int value)
{
  if (index < 0 || index >= this->size) {
    return;
  }
  this->array[index] = value;
}

std::optional<int> DynamicArray::get(int index) const
{
  if (index < 0 || index >= this->size) {
    return std::nullopt;  // ERROR: index out of range
  }
  return this->array[index];
}

void DynamicArray::insert(int index, int value)
{
  if (index < 0 || index >= this->size) {
    return;  // ERROR: index out of range
  }

  if (this->size >= this->capacity) {
    this->resize();
  }

  for (int i = this->size - 1; i >= index; i--) {
    this->array[i + 1] = this->array[i];
  }
  this->array[index] = value;
  this->size++;
}

void DynamicArray::remove(int index)
{
  if (index < 0 || index >= this->size) {
    return;  // ERROR: index out of range
  }

  for (int i = index; i < this->size; i++) {
    this->array[i] = this->array[i + 1];
  }
  this->size--;
}

std::optional<int> DynamicArray::find(int value) const
{
  for (int i = 0; i < this->size; i++) {
    if (this->array[i] == value)
      return i;
  }
  return std::nullopt;
}

void DynamicArray::resize()
{
  std::unique_ptr<int[]> new_array(new int [this->capacity * 2]);

  for (int i = 0; i < this->size; i++) {
    new_array[i] = this->array[i];
  }

  this->array = std::move(new_array);
  this->capacity = this->capacity * 2;
}

}  // namespace mf
