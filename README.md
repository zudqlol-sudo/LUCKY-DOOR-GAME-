# Lucky Doors - C Game

A small 2D game of chance written in C using the **raylib** graphics library.

## How to play

- You start with 3 lives.
- Click one of the three doors.
- A door randomly gives you 20 points, 40 points, or removes one life.
- Reach 100 points to win.
- Lose all 3 lives, or finish 10 rounds without reaching 100 points, to lose.
- Press **R** on the result screen to restart.
- Close the window to quit.

## Requirements

- A C compiler (GCC or MinGW-w64)
- raylib

## Build on Windows (MinGW-w64)

Install raylib for MinGW-w64, then compile from the project folder. A common command is:

```bash
gcc main.c -o LuckyDoors.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```

The exact command can vary depending on how raylib was installed and where its files are located.

## Build on Linux

Install GCC and raylib development files, then run:

```bash
gcc main.c -o lucky-doors -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./lucky-doors
```

## What the code demonstrates

- Variables for score, lives, and game state
- An array of rectangles for the three doors
- A `while` loop for the game loop
- `if` / `else` statements for rewards and end conditions
- `rand()` for random outcomes
- Mouse input and drawing functions from raylib

## Project files

- `main.c` - complete game source code
- `Makefile` - example build commands for Linux
