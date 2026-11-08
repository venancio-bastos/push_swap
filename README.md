# push_swap

A sorting program for integers, built for the 42 Porto curriculum. It prints the sequence of stack operations needed to sort a list of numbers, using two stacks (`a` and `b`) and the operations defined in the subject. The goal is to use as few operations as possible.

A bonus `checker` program reads a sequence of operations from the standard input, applies it to the input numbers, and prints `OK` if the stack ends up sorted or `KO` if it does not.

## Algorithm

Stack `a` starts with the input numbers and stack `b` is empty. For lists of more than three numbers, the program uses the Turk algorithm:

1. Push numbers from `a` to `b`, leaving three numbers in `a`. For each candidate, it computes the cheapest combined rotation cost to move it.
2. Sort the three numbers left in `a` with a fixed set of moves.
3. Move numbers from `b` back to `a` one at a time, each at the position where it belongs. Each move uses the cheapest rotation cost computed beforehand.
4. Rotate `a` so that the smallest number is at the top.

Stacks are doubly linked lists of nodes that hold the value, the index, the target position and the cost of each move.

Special cases:
- Two numbers: a single `sa` if they are out of order.
- Three numbers: a fixed sequence of moves (`sort_tiny`).

## Operations

| Operation | Effect |
|-----------|--------|
| `sa`, `sb`, `ss` | Swap the first two elements of `a`, of `b`, or both |
| `pa`, `pb` | Move the top element from `b` to `a`, or from `a` to `b` |
| `ra`, `rb`, `rr` | Rotate `a`, `b`, or both upwards |
| `rra`, `rrb`, `rrr` | Reverse rotate `a`, `b`, or both downwards |

## Build

```bash
make          # builds push_swap
make bonus    # builds checker
make clean    # removes object files
make fclean   # removes object files and both programs
make re       # fclean + all
```

## Usage

Arguments can be separate numbers or a single quoted string:

```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```

With no arguments, or with invalid input, the program writes `Error` to standard error and exits.

Input is rejected when it contains:
- a value that is not an integer;
- a value outside the `int` range;
- a duplicate number.

Verify a sequence with the checker:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

Or type operations by hand and finish with `Ctrl-D`:

```bash
./checker 3 2
sa
```

The checker prints `OK` if the sequence sorts the numbers, `KO` if it does not, and `Error` for invalid input.

## Tests

I checked the program in two ways:

- **Correctness:** random inputs of 3, 5, 100 and 500 numbers (three seeds each), checked with `checker`. All 12 results were `OK`.
- **Sanitizers:** the `push_swap` and `checker` builds, compiled with AddressSanitizer and UndefinedBehaviorSanitizer, showed no errors or leaks on normal inputs or on invalid inputs (duplicates, letters, overflow, empty input).

Operation counts from those runs:

| Numbers | Operations observed |
|---------|---------------------|
| 3       | 1 to 2              |
| 5       | 5 to 8              |
| 100     | 560 to 621          |
| 500     | 5127 to 5653        |

The 500-number case with the highest count (5653) is above the 5500 operations usually expected for this benchmark. The other two cases are below it.

## Known limitations

- Only three random seeds were tested per size, so these counts are a sample, not a guarantee for every input.
- The 500-number case above exceeded 5500 operations in one of three runs.

## Project structure

```
includes/push_swap.h        # node structure and prototypes
src/push_swap.c             # entry point and argument handling
src/checker.c               # bonus checker
utils/commands/             # the eleven stack operations
utils/push_swap/            # sorting logic: Turk algorithm and tiny cases
utils/input_check.c         # argument parsing and validation
utils/stack_utils.c         # stack helpers
utils/gnl/                  # get_next_line, used by the checker
```
