*This project has been created as part of the 42 curriculum by vebastos.*

# Push_swap

## Description

**Push_swap** is a 42 school algorithmic project that requires sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for optimized data sorting.

The goal is to write a program in C called `push_swap` which calculates and displays on the standard output the moves it had to make to sort the integers received as arguments.

This implementation utilizes the **Turk Algorithm**, a highly efficient strategy for this specific problem in this context. It works by pushing nodes from stack A to B intelligently (calculating the cheapest cost to move), and then moving them back to A in the correct order.

---
## Instructions

The Instructions the algorithm takes and uses after deciding which is the cheapest are:

**swap moves**

sa - (swap a): Swap the first 2 elements at the top of stack a.

sb - (swap b): Swap the first 2 elements at the top of stack b.

ss - sa and sb at the same time.

**push moves**

pa - (push a): Take the first element at the top of b and put it at the top of a.

pb - (push b): Take the first element at the top of a and put it at the top of b.

**rotate moves**

ra - (rotate a): Shift up all elements of stack a by 1. (The first element becomes the last one.)

rb (rotate b): Shift up all elements of stack b by 1. (The first element becomes the last one.)

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1. (The last element becomes the first one.)

rrb (reverse rotate b): Shift down all elements of stack b by 1. (The last element becomes the first one.)

rrr : rra and rrb at the same time.

---
### Resources

In this project I have researched which algorithms were there to tackle this problem and which one was efficient enough for
the ammount of moves required for the benchmark.

I ultimately decided to choose the **Turk** because it calculates which moves are more effective to make before doing so, also, it takes
full advantage of the doubled linked lists I decided on using turning it more efficient.

For the project I have watched tutorials on Youtube explaining how the algorithm worked and during the project i used **GEMINI PRO** to
help me keep track of the whole logic behind it and to assist me with **bug patching**.

---
#### Compilation

The project uses a `Makefile` for compilation. To compile the `push_swap` executable, simply run:

```bash
make
```

And to compile the checker program:
```bash
make bonus
```
