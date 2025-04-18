#ifndef BOARD_HT_HPP
#define BOARD_HT_HPP

#include <cstddef>
#include <unordered_map>
#include <memory>  
#include "bitvector.hpp"

struct BoardData {
    bitvector board;
};

class BoardHashTable {
public:
    BoardHashTable(size_t capacity);
    ~BoardHashTable();

    // Insert a new board data
    void insert(std::unique_ptr<BoardData> data);

    // Look up a board data
    BoardData* lookup(const bitvector& board);

private:
    size_t keyHash(const bitvector& key) const;
    bool keyEqual(const bitvector& key1, const bitvector& key2) const;

    // Use unordered_map as the underlying hash table
    std::unordered_map<bitvector, std::unique_ptr<BoardData>, std::hash<bitvector>, std::equal_to<bitvector>> map;
};

#endif // BOARD_HT_HPP
