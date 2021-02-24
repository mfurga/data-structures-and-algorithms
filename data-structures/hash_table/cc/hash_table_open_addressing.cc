#include <functional>
#include "hash_table_open_addressing.h"

namespace mf
{

template <class K, class V>
HashTable<K, V>::HashTable() : m_(8), n_(0)
{
  array_ = new HashTableEntry<K, V>*[m_];
  for (int i = 0; i < m_; i++) {
    array_[i] = nullptr;
  }
  dummy_ = new HashTableEntry<K, V>();
}

template <class K, class V>
void HashTable<K, V>::resize_()
{
  HashTableEntry<K, V> **array = new HashTableEntry<K, V>*[m_ * 2];
  for (int i = 0; i < m_ * 2; i++) {
    array[i] = nullptr;
  }
  m_ *= 2;

  int h;
  for (int j = 0; j < m_ / 2; j++) {
    if (array_[j] != nullptr && array_[j] != dummy_) {
      HashTableEntry<K, V> *entry = \
        new HashTableEntry<K, V>(array_[j]->key, array_[j]->value);
      h = hash_(array_[j]->key);

      while (array[h] != nullptr) {
        h = (h + 1) % m_;
      }
      array[h] = entry;
    }
  }

  for (int k = 0; k < m_ / 2; k++)
    delete array_[k];
  delete [] array_;
  array_ = array;
}

template <class K, class V>
int HashTable<K, V>::hash_(const K &key) const
{
  return std::hash<K>()(key) % m_;
}

template <class K, class V>
void HashTable<K, V>::insert(const K &key, const V &value)
{
  if (n_ / static_cast<float>(m_) > 0.6) {
    resize_();
  }

  int h = hash_(key);

  while (array_[h] != nullptr && array_[h] != dummy_) {
    if (array_[h]->key == key) {
      array_[h]->value = value;
      return;
    }
    h = (h + 1) % m_;
  }

  array_[h] = new HashTableEntry<K, V>(key, value);
  n_++;
}

template <class K, class V>
std::optional<const V> HashTable<K, V>::get(const K &key) const
{
  int h = hash_(key);

  if (array_[h] == nullptr || array_[h] == dummy_)
    return std::nullopt;

  do {
    if (array_[h]->key == key) {
      return array_[h]->value;
    }
    h = (h + 1) % m_;
  } while (array_[h] != nullptr && array_[h] != dummy_);

  return std::nullopt;
}

template <class K, class V>
void HashTable<K, V>::remove(const K &key)
{
  int h = hash_(key);

  if (array_[h] == nullptr || array_[h] == dummy_)
    return;

  do {
    if (array_[h]->key == key) {
      delete array_[h];
      array_[h] = dummy_;
      n_--;
      return;
    }
    h = (h + 1) % m_;
  } while (array_[h] != nullptr && array_[h] != dummy_);
}
}  // namespace mf
