# Skyscraper Solver

This program solves a 4 × 4 Skyscraper puzzle.

## Usage

Pass the puzzle clues to the program as a single string argument. For example:

```text
"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

The clues are arranged in the following order:

1. Top clues, for the columns from left to right.
2. Bottom clues, for the columns from left to right.
3. Left clues, for the rows from top to bottom.
4. Right clues, for the rows from top to bottom.

For example, the input above represents:

```text
        4   3   2   1
      +---+---+---+---+
  4   |   |   |   |   |   1
      +---+---+---+---+
  3   |   |   |   |   |   2
      +---+---+---+---+
  2   |   |   |   |   |   2
      +---+---+---+---+
  1   |   |   |   |   |   2
      +---+---+---+---+
        1   2   2   2
```

## Output

The program prints the first valid solution it finds for the given input, if one exists.

It prints `Error` if:

- The input is incorrectly formatted.
- The program does not receive exactly one argument.
- No solution exists for the given puzzle.

## Method

The solver uses a backtracking algorithm to explore possible solutions.
