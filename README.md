# BSQ
The program st find the largest possible square on a board while avoiding obstacles.
The board can be generated two ways. The first one is by reading a file passed as the program’s argument


The file is valid if it is respecting those constraints:
  • its first line contains the number of lines on the board (and only that),
  • “.” (representing an empty place) and “o” (representing an obstacle) are the only two characters for the
  other lines,
  • all of the lines are of the same length (except the first one),
  • it contains at least one line,
  • each line is terminated by ‘\n’.
You program must print the board, with some “.” replaced by “x” to represent the largest square you found.


(If ever there are several solutions, you have to represent only the highest square. If they are still several solutions, choose the square to the left.)


The second way to obtain a board is to generate one based on given parameters. The parameters will be a number, representing the width and height of the board, and a pattern that will be repeated line by line along the board.
You will print the solved board.
