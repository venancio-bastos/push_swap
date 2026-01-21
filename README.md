*This project has been created as part of the 42 curriculum by ruisilva*

# Push_swap

## Description

**Push_Swap** is a 42 school project about algorithms. The goal is to sort data on a stack, using only a limited number of operations and an auxiliary stack. To pass, you have to use the lowest possible number of operations. To make this achievable, you have to choose an algorithm for data sorting.

The program calculates and displays on the standard output the operations needed to sort the integers passed as arguments.

## Algorithm

I implemented the **Turk  Algorithm** a highly efficient strategy for this specific problem in this context. It works by pushing nodes from stack A to B intelligently (calculating the cheapest cost to move), and then moving them back to A in the correct order:

## Operations

- `sa` (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.
- `sb` (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.
- `ss` : sa and sb at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- `pb` (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
- `ra` (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
- `rr` : ra and rb at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
- `rrr` : rra and rrb at the same time.

## Instructions
### 1. Compilation
To compile the `push_swap` program:

```bash
make
```

To compile the bonus `checker` program:

```bash
make bonus
```

### 2. Execution
Run the `push_swap` program with a list of integers:

```bash
./push_swap 2 1 3 6 5 8
```

You can run the `checker` to verify the output:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

You can also run the `checker` by itself and type on the standard input the instructions you wish to use yourself:

```bash
./checker 3 2
```

If you then type `sa` and press `Enter`, then `CTRL-D`, the program should output `OK`.


### 3. Cleaning
To remove object files:

```bash
make clean
```

To remove object files and programs:

```bash
make fclean
```

## Resources

In this project I have researched which algorithms were there to tackle this problem and which one was efficient enough for the ammount of moves required for the benchmark.

I ultimately decided to choose the Turk because it calculates which moves are more effective to make before doing so, also, it takes full advantage of the doubled linked lists I decided on using turning it more efficient.

For the project I have watched **tutorials on Youtube** explaining how the algorithm worked and during the project i used **GEMINI PRO** to help me keep track of the whole logic behind it and to assist me with bug patching.

### AI Usage
- **Turk Concept:** AI was used to understand the math behind the algorithm and how to implement.
- **C Concepts:** AI was consulted to clarify specific C concepts.
- **Project Structure:** AI assisted in clarifying the best practices in projects with multiple makefiles. AI also helped in formatting this README.