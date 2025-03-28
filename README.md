<div align="center">
  <img height="200" src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/pushswap.png"  />
</div>

# Push Swap - Sorting Algorithm Project

Push Swap is a project that challenges you to develop a program to sort a stack of integers using a specific set of rules and a minimal number of operations. It will test your algorithmic thinking and your ability to write efficient and optimized C code.

## Status
<div align="center">
  <img height="200" src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/pushswap_success.png"  />
</div>

## Example
<div align="center">
  <img src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/pushswap_exp.gif"  />
</div>

## Objectives

The goal of this project is to write a program that sorts a stack of integers using only two stacks (A and B) and a predefined set of operations. You'll learn about sorting algorithms, data structures (stacks), and the importance of optimization.

## Great Resources

<li><a href="https://github.com/o-reo/push_swap_visualizer">Push Swap Visualizer</a></li>
<li><a href="https://github.com/SimonCROS/push_swap_tester">Push Swap Tester</a></li>
<li><a href="https://medium.com/@ayogun/push-swap-c1f5d2d41e97">Turkish Algorithm by A. Yigit Ogun</a></li>

## Mandatory

<table>
  <tr>
    <th>Program name</th>
    <td>push_swap</td>
  </tr>
  <tr>
    <th>Turn in files</th>
    <td>All necessary files to compile the program</td>
  </tr>
  <tr>
    <th>Makefile</th>
    <td>Yes</td>
  </tr>
  <tr>
    <th>External functions</th>
    <td>write, read, malloc, free, exit</td>
  </tr>
  <tr>
    <th>Libft authorized</th>
    <td>Yes</td>
  </tr>
  <tr>
    <th>Description</th>
    <td>Sort integers using two stacks and the minimum number of operations.</td>
  </tr>
</table>

- The project must be written in C.
- Code must adhere to the Norm.
- No memory leaks are tolerated; all allocated memory must be freed.
- Provide a Makefile to compile the program with flags `-Wall -Wextra -Werror`.
- The Makefile must include rules for `all`, `clean`, `fclean`, and `re`.

## Functionality

The program should:

- Take as input a series of integers (either directly or from the command line) and sort them.
- Use two stacks (A and B) to perform the sorting.
- Implement the following operations:
  - `sa`, `sb`, `ss` — Swap the first two elements of a stack.
  - `pa`, `pb` — Push the first element from one stack to the other.
  - `ra`, `rb`, `rr` — Rotate the stack (shift all elements up, the first element becomes the last).
  - `rra`, `rrb`, `rrr` — Reverse rotate the stack (shift all elements down, the last element becomes the first).

- Minimize the number of operations to sort the stack.
- Handle edge cases such as:
  - Invalid input.
  - Duplicate integers.
  - Extremely small or large stacks efficiently.

## Bonuses

If the mandatory part is completed perfectly, consider the following bonus features:

- Create a checker program (`checker`) that:
  - Reads a list of operations from standard input and applies them to the stacks to verify if the input was sorted correctly.
  - Displays "OK" if the stack is sorted and "KO" otherwise.

Bonus files should be named with the `_bonus` suffix.

---

## Example Usage

```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG
ra
pb
sa
pa
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
```
