# BSQ

# Compilation

Via Makefile

```bash
make
```
# Description

You must find the largest possible square on a board while avoiding obstacles.
The board can be generated two ways. The first one is by reading a file passed as the program’s argument

The second way to obtain a board is to generate one based on given parameters. The parameters will be
a number, representing the width and height of the board, and a pattern that will be repeated line by line
along the board

(If ever there are several solutions, you have to represent only the highest square. If they
are still several solutions, choose the square to the left.)

# Usage
## with a file
```bash
./bsq map
```
## without a file
```bash
./bsq 100 "..oo"
./bsq "Number" "Patern"
```
