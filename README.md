# queens
finds the number of solutions to the N-Queens problem on a board with a provided size

This program works with recursion and depth-first search to find how many solutions there are to the N-queens problem, a relatively well known mathematical problem.  Consider a chess board of an abritrary size NxN with N queens placed on it such that no queen lies in the same row, column, or on the same diagonal of another queen.  Taking in the size of the board as a command line argument, this program returns the answer relatively quick; however, it takes exponentially more time with a larger board.  A standard chess board is of size 8x8, and this program returns its solution of 92 in about 0.002 seconds and returns the solution for a 14x14 board (365596) in about ten seconds on my computer.
