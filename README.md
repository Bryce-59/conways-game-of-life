# About the Project
A demo of Conway's Game of Life in C++ from 2022.

The rules are very simple. From the Wikipedia description of the game:
- Any live cell with fewer than two live neighbours dies, as if by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

Conway's Game of Life is a zero-player game, which means that it plays autonomously after the initial configuration is decided. The input format should be as follows.
- The first line of input contains a single integer `N`.
- The second line is left empty.
- The next `N` blocks of code follow the proceeding pattern: 
    - The first line contains the height and width of the game board.
    - The second line contains a single integer `M`.
    - The next `M` lines of code contain the coordinates of cells that are live when Time = 0. The remaining cells should be dead.
    - The final line is left empty.

Example Input:
```
1

10 10
4
2 2
2 3
3 2
3 3

```
Example Output:
```
*** Conway's Game of Life 10x10 ***

Time = 0, Population = 4.
..........
..........
..**......
..**......
..........
..........
..........
..........
..........
..........
```

The Conway Cell is a subclass of the Abstract Cell, so that other cells with alternate rules can easily be implemented later if desired.

# How to Use
To run the program against keyboard input, use the Make command `make run`.
To run the program against test input, use `make run-test`.

The driver file is `RunLifeConway.cpp`, if your device does not support Make.

# Credits
- 2022 Bryce Richardson

# License
- [MIT License](https://choosealicense.com/licenses/mit/)