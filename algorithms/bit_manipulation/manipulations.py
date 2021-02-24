#!/usr/bin/env python2
# Simple bit manipulation.

def set_bit(number, position):
  """
  Sets the bit on high in the specified `position`.
  """
  mask = 1 << position
  return number | mask

def clear_bit(number, position):
  """
  Sets the bit on low in the specified `position`.
  """
  mask = 1 << position
  return number & ~mask

def flip_bit(number, position):
  """
  Flips the bit in the specified `position`.
  """
  mask = 1 << position
  return number ^ mask

def get_bit(number, position):
  """
  Gets the bit in the specified `position`.
  """
  return (number >> position) & 0b1

def modify_bit(number, position, state):
  """
  Modifies the bit in the specified `position` using the 
  `state` parameter.
  """
  mask = 1 << position
  return (number & ~mask) | (-state & mask)

def is_even(number):
  """
  Checks if the given `number` is even.
  """
  return not number & 0b1

def is_power_of_two(number):
  """
  Checks if the given `number` is power of two.
  """
  return (number & number - 1) == 0

def count_different_bits(a, b):
  """
  Counts the number of bits that are different between
  two numbers.
  """
  return sum([((a >> shift) & 1) ^ ((b >> shift) & 1) for shift in xrange(max(a.bit_length(), b.bit_length()))])


if __name__ == '__main__':
  number = 0b10111  # 23

  # Set bit tests
  assert set_bit(number, 0) == 0b10111
  assert set_bit(number, 5) == 0b110111
  assert set_bit(number, 3) == 0b11111
  assert set_bit(number, 6) == 0b1010111

  # Clear bit tests
  assert clear_bit(number, 4) == 0b111
  assert clear_bit(number, 0) == 0b10110
  assert clear_bit(number, 3) == 0b10111
  assert clear_bit(number, 5) == 0b10111

  # Flip bit tests
  assert flip_bit(number, 0) == 0b10110
  assert flip_bit(number, 4) == 0b111
  assert flip_bit(number, 3) == 0b11111
  assert flip_bit(number, 5) == 0b110111

  # Get bit tests
  assert get_bit(number, 0) == 0b1
  assert get_bit(number, 3) == 0b0
  assert get_bit(number, 4) == 0b1
  assert get_bit(number, 5) == 0b0

  # Modify bit tests
  assert modify_bit(number, 0, 0) == 0b10110
  assert modify_bit(number, 3, 1) == 0b11111
  assert modify_bit(number, 4, 0) == 0b111
  assert modify_bit(number, 4, 1) == 0b10111
  assert modify_bit(number, 5, 1) == 0b110111

  # Is even tests
  assert is_even(number) == False
  assert is_even(2) == True

  # Is power of two tests
  assert is_power_of_two(2) == True
  assert is_power_of_two(23) == False
  assert is_power_of_two(1) == True

  assert count_different_bits(0b111, 0b000) == 3
  assert count_different_bits(0b11100, 0b000) == 3
