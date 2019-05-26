#!/usr/bin/evn python2
# Python has a built-in implementation of the dynamic array named 'list'.

def main():
  dynamic_array = []

  # Add an item to the end of the list.
  dynamic_array.append(1)
  dynamic_array.append(2)

  # Insert an item at a given position.
  dynamic_array.insert(0, 3)

  # Remove the item at the given position in the list, and return it. 
  dynamic_array.pop()  # Returns 2

  # Return the index in the list of the first item whose value is 3.
  dynamic_array.index(3)  # Returns 0

  # Sort the items of the list in place.
  dynamic_array.sort()

  print dynamic_array


if __name__ == '__main__':
  main()