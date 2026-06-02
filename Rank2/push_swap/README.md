*This project has been created as part of the 42 curriculum by tthwe*

# push_swap

## Description

**push_swap** is a sorting algorithm project. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, producing the smallest possible sequence of moves.

Stack `a` begins with a random list of integers. Stack `b` starts empty. The program must output the sequence of operations that sorts stack `a` in ascending order with the minimum number of instructions.

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the top two elements of stack a |
| `sb` | Swap the top two elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top element of stack b onto stack a |
| `pb` | Push the top element of stack a onto stack b |
| `ra` | Rotate stack a upward (top goes to bottom) |
| `rb` | Rotate stack b upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack a (bottom goes to top) |
| `rrb` | Reverse rotate stack b |
| `rrr` | `rra` and `rrb` simultaneously |

### Algorithm

The program uses a **greedy insertion algorithm**:

1. Push all elements except 3 from stack `a` to stack `b`
2. Sort the remaining 3 elements in stack `a`
3. For each element in stack `b`, calculate the cost of rotating both stacks to insert it into the correct position in stack `a`, then push the cheapest one
4. Repeat until stack `b` is empty
5. Rotate stack `a` to bring the minimum element to the top

This approach achieves the benchmarks:
- 100 numbers: under 700 operations
- 500 numbers: under 5500 operations

## Instructions

### Requirements

- GCC compiler
- `make`

### Build

```bash
git clone https://github.com/meganing/42_Projects.git
cd Rank2/push_swap
make
```

This compiles the Libft library and produces the `push_swap` executable.

### Usage

```bash
./push_swap <integer1> <integer2> ... <integerN>
```

The program prints the list of operations to stdout, one per line.

### Cleanup

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Full rebuild
```

## Examples

```bash
# Simple case
$ ./push_swap 2 1 3
sa

# Larger input
$ ./push_swap 5 2 8 1 9 3
pb
pb
sa
pa
ra
pa
rra

# Already sorted — no output
$ ./push_swap 1 2 3

# Error cases
$ ./push_swap 1 2 a
Error
$ ./push_swap 1 2 2
Error
$ ./push_swap 2147483648
Error
```

## Resources

### Algorithm References

- [Comparison Sort Algorithms for Dummies](https://medium.com/marktech/comparison-sort-algorithms-for-dummies-e621cbff2c3f) - good article to start, the visualization are easy for us to grasp the concept
- [push_swap](https://dynamicdispat.ch/posts/2024/01/push-swap/) - a nice intro blog to the project
- [Push_Swap: An Easy and Efficient Sorting Algorithm](https://medium.com/@julien-ctx/push-swap-an-easy-and-efficient-algorithm-to-sort-numbers-4b7049c2639a) - very good explanation on the project
- [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer) - useful for visualizing operation sequences

### AI Usage

AI was used during this project for:

- Algorithm explanation: Explaining and comparing different algorithms during early implementation process
- Norminette compliance: Reformatting all C source files to comply with 42 school Norminette v3 rules.
- Bug diagnosis: Identifying a critical insertion-position bug where stack `a` was being rotated to `target` instead of `target->next`, causing elements to be inserted in the wrong order and breaking the circular ascending invariant

