#ifndef HASH_TABLE_OPEN_ADDRESSING_H
#define HASH_TABLE_OPEN_ADDRESSING_H

#include <string>
#include <memory>
#include <optional>

namespace mf
{

template <class K = std::string, class V = int>
struct HashTableEntry
{
  K key;
  V value;

  HashTableEntry() {}
  HashTableEntry(const K &key, const V &value) : key(key), value(value) {}
};

template <class K = std::string, class V = int>
class HashTable
{
 private:
  int m_;
  int n_;
  HashTableEntry<K, V> **array_;
  HashTableEntry<K, V> *dummy_;

  void resize_();
  int hash_(const K &key) const;

 public:
  HashTable();
  ~HashTable() {};

  void insert(const K &key, const V &value);
  std::optional<const V> get(const K &key) const;
  void remove(const K &key);
};

}  // namespace mf

#endif  // HASH_TABLE_OPEN_ADDRESSING_H
