#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
#include "bitvector.hpp"   
#include "board-ht.hpp"     
#include "contracts.hpp" 

// A Board class to encapsulate board state and related functions
class Board {
public:
    BitVector board;
    BitVector vec;

    Board(BitVector b) : board(b), vec(BitVector::new_empty()) {}

    // Toggle a specific button and its neighbors
    static BitVector button(int row, int col, BitVector b, uint8_t width, uint8_t height) {
        b.flip(get_index(row, col, width, height));
        if (is_valid_pos(row, col - 1, width, height)) {
            b.flip(get_index(row, col - 1, width, height));
        }
        if (is_valid_pos(row - 1, col, width, height)) {
            b.flip(get_index(row - 1, col, width, height));
        }
        if (is_valid_pos(row, col + 1, width, height)) {
            b.flip(get_index(row, col + 1, width, height));
        }
        if (is_valid_pos(row + 1, col, width, height)) {
            b.flip(get_index(row + 1, col, width, height));
        }
        return b;
    }

    // Check if the board is solved (all lights off)
    bool is_solved() const {
        return board == BitVector::new_empty(); 
    }
};

// A LightsOut class to manage the game logic
class LightsOut {
private:
    Board board;
    uint8_t width, height;
    std::unordered_map<BitVector, std::unique_ptr<Board>> visited;
    std::queue<std::unique_ptr<Board>> q;

public:
    LightsOut(Board b, uint8_t w, uint8_t h) : board(b), width(w), height(h) {}

    // Process the board and attempt to solve it
    void solve() {
        q.push(std::make_unique<Board>(board));
        visited[board.board] = std::make_unique<Board>(board);

        while (!q.empty()) {
            auto current = std::move(q.front());
            q.pop();

            if (current->is_solved()) {
                print_pushes(current->vec, width);  // Print solution
                return;
            }

            for (int row = 0; row < height; ++row) {
                for (int col = 0; col < width; ++col) {
                    BitVector new_board = Board::button(row, col, current->board, width, height);
                    BitVector new_vec = current->vec.flip(get_index(row, col, width, height));

                    if (visited.find(new_board) == visited.end()) {
                        auto new_state = std::make_unique<Board>(new_board);
                        new_state->vec = new_vec;
                        visited[new_board] = std::move(new_state);
                        q.push(std::move(new_state));
                    }
                }
            }
        }

        std::cerr << "No solution found" << std::endl;
    }

    // Load board from file
    bool load_board(const std::string& filename) {
        // Assume file_read loads the board and sets width and height
        return file_read(filename, board.board, width, height);
    }
};

// Main game loop
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: lightsout <board name>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string board_filename = argv[1];
    Board initial_board(BitVector::new_empty());  // Create an empty board initially
    LightsOut game(initial_board, 5, 5);  // 5x5 board (just an example)

    if (!game.load_board(board_filename)) {
        std::cerr << "Failed to load the board" << std::endl;
        return EXIT_FAILURE;
    }

    game.solve();
    return EXIT_SUCCESS;
}
