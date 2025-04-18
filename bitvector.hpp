#ifndef BITVECTOR_HPP
#define BITVECTOR_HPP

#include <cstdint>

const uint8_t BITVECTOR_LIMIT = 64; 

using bitvector = uint64_t; 

bitvector bitvector_new();  // Create a new bitvector
bool bitvector_get(bitvector B, uint8_t i);  // Get the i-th bit of B
bitvector bitvector_flip(bitvector B, uint8_t i);  // Flip the i-th bit of B
bool bitvector_equal(bitvector B1, bitvector B2);  // Check if two bitvectors are equal

#endif  // BITVECTOR_HPP
