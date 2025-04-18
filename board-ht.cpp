#include "board-ht.hpp"
#include <stdexcept>
#include <iostream>
#include "bitvector.hpp"

BoardHashTable::BoardHashTable(size_t capacity) {
    map.reserve(capacity);  // Pre-allocate space if desired
}

BoardHashTable::~BoardHashTable() {
    // Automatically cleans up memory used by map since it's a smart container
}

void BoardHashTable::insert(BoardData* data) {
    if (lookup(data->board) != nullptr) {
        throw std::invalid_argument("Board already exists in the table.");
    }

    // Insert into map (board -> data)
    map[data->board] = data;
}

BoardData* BoardHashTable::lookup(const bitvector& board) {
    auto it = map.find(board);
    if (it != map.end()) {
        return it->second;  // Return the associated BoardData
    }
    return nullptr;  // Return nullptr if not found
}

size_t BoardHashTable::keyHash(const bitvector& key) const {
    // Optimized hash function using std::hash
    size_t hashValue = 0;
    for (int i = 0; i < BITVECTOR_LIMIT; i++) {
        bool bit = bitvector_get(key, i);
        hashValue = (hashValue << 1) ^ (bit ? 1 : 0);
    }
    return hashValue;
}

bool BoardHashTable::keyEqual(const bitvector& key1, const bitvector& key2) const {
    return bitvector_equal(key1, key2);  // Direct comparison of bitvectors
}
