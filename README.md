# LightsOut Game

This project implements the LightsOut game with a custom board and bitvector system. The goal of the game is to turn off all the lights on the board by toggling them. Each toggle changes the state of the light and its adjacent lights.

## Project Structure

The project consists of the following files:

### Source Code:
- **bitvector.cpp**: Contains the implementation of a `BitVector` class, used to manage a collection of bits efficiently. This class supports operations like toggling, setting, and getting individual bits.
- **bitvector.hpp**: The header file defining the `BitVector` class. It includes the function declarations for bit manipulation and storage.
- **board-ht.cpp**: Implements the `Board` class for the LightsOut game. This class manages the state of the game, including the lights on the board and the logic to toggle lights.
- **board-ht.hpp**: The header file defining the `Board` class. It includes function declarations for manipulating the board state, toggling lights, and checking the game status.
- **lightsout.cpp**: Contains the main game logic for playing the LightsOut game, including solving the game and interacting with the user. This file ties together the bitvector and board components to run the game.
