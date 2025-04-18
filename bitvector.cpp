#include "bitvector.hpp"
#include <cassert>

bitvector bitvector_new() {
    return 0;  
}

bool bitvector_get(bitvector B, uint8_t i) {
    assert(i < BITVECTOR_LIMIT);  // Ensure the index is within bounds
    bitvector val = static_cast<bitvector>(1) << i;  // Create a bitmask for the i-th bit
    return (B & val) != 0;  // Return true if the bit is set, false otherwise
}

bitvector bitvector_flip(bitvector B, uint8_t i) {
    assert(i < BITVECTOR_LIMIT);  // Ensure the index is within bounds
    bitvector val = static_cast<bitvector>(1) << i;  // Create a bitmask for the i-th bit
    return B ^ val;  // Flip the i-th bit by XORing with 1
}

bool bitvector_equal(bitvector B1, bitvector B2) {
    return B1 == B2;  // Compare bitvectors directly
}
