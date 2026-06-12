*This project has been created as part of the 42 curriculum by gopiment, danicamp.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a list of integers using two stacks (`a` and `b`) and a restricted set of operations, using the fewest operations possible.

The project requires implementing four distinct sorting strategies — simple O(n²), medium O(n√n), complex O(n log n), and an adaptive algorithm that selects a strategy based on a disorder metric computed from the initial state of the stack.

A bonus **checker** program is also included, which reads a sequence of operations from stdin and verifies whether they correctly sort the original stack.

---

## Instructions

### Compilation

```bash
# Build push_swap
make

# Build checker (bonus)
make bonus

# Clean object files
make clean

# Full clean (removes binaries)
make fclean

# Rebuild everything
make re
```

### Usage

```bash
# Sort with default adaptive strategy
./push_swap 4 67 3 87 23

# Force a specific strategy
./push_swap --simple  5 4 3 2 1
./push_swap --medium  5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1

# Show benchmark metrics (sent to stderr)
./push_swap --bench 4 67 3 87 23

# Combine flags
./push_swap --bench --complex 4 67 3 87 23

# Count operations
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l

# Verify correctness with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

### Error handling

The program prints `Error` to stderr and exits on invalid input: non-integer arguments, values outside the int range, or duplicate values.

```bash
./push_swap 1 two 3   # Error
./push_swap 1 1 2     # Error
```

---

## Algorithms

### Disorder metric

Before sorting, the program computes a **disorder score** between `0.0` (already sorted) and `1.0` (worst case). It counts all pairs `(i, j)` where `i < j` but `a[i] > a[j]` (inversions), divided by the total number of pairs:

```
disorder = inversions / total_pairs
```

This value drives the adaptive strategy selection.

### 1. Simple — O(n²) — *danicamp*

An insertion sort adaptation. The algorithm scans stack `a` for descending runs, pushing elements that break the order to stack `b`. It then inserts each element from `b` back into `a` at the correct position using best-rotation helpers to minimize operations.

Complexity argument: for each of the n elements pushed to `b`, finding the insertion point in `a` requires at most n/2 rotations → O(n²) operations total.

### 2. Medium — O(n√n) — *gopiment*

A chunk-based sorting strategy. The stack is divided into `√n` chunks based on normalized index values. Elements belonging to the current chunk are pushed to `b` using the cheapest rotation (from top or bottom of `a`). Once all chunks are in `b`, elements are pulled back to `a` in order by always rotating to the maximum.

Complexity argument: `√n` chunks × O(n) rotations per chunk to push + O(n) rotations to pull back → O(n√n) operations total.

### 3. Complex — O(n log n) — *danicamp*

LSD Radix sort adapted to the two-stack model. Elements are assigned a normalized index (rank). The algorithm processes each bit of those indices from least significant to most significant. On each pass, elements with a `0` bit at the current position are pushed to `b`; others stay in `a` via `ra`. At the end of each pass, all elements in `b` are pushed back to `a`. After `log₂(n)` passes, the stack is sorted.

Complexity argument: `log₂(n)` passes × n operations per pass → O(n log n) operations total.

### 4. Adaptive — *gopiment + danicamp*

Selects a strategy at runtime based on the computed disorder:

| Disorder | Strategy | Complexity |
|---|---|---|
| `< 0.2` | Medium (chunk sort) | O(n√n) |
| `0.2 ≤ d < 0.5` | Medium (chunk sort) | O(n√n) |
| `≥ 0.5` | Complex (radix sort) | O(n log n) |
| `≤ 5 elements` | Small sort (hardcoded) | O(1) |

**Threshold rationale:** at low disorder the stack is nearly sorted; a simple approach is sufficient. At high disorder (≥ 0.5) the number of inversions is large enough that the logarithmic cost of radix sort outperforms the quadratic behaviour of simpler methods. The medium range uses chunk sort as a balanced middle ground.

**Space complexity:** both medium and complex operate in O(n) additional space (stack `b` holds at most n elements at any time).

### Small sort

Hardcoded optimal sequences for 2, 3, 4, and 5 elements — *gopiment*. Used as the base case for all strategies when `n ≤ 5`.

---

## Performance targets

| Input size | Pass | Good | Excellent |
|---|---|---|---|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Contributions

| Login | Contributions |
|---|---|
| **gopiment** | Parsing & input validation, medium algorithm (chunk sort), small sort (2–5 elements), benchmark mode (`--bench`), checker bonus |
| **danicamp** | Complex algorithm (LSD radix sort), simple algorithm (insertion sort adaptation), all stack operations (push, swap, rotate, reverse rotate) |

---

## Resources

- [Sorting algorithms — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Introduction to Algorithms (CLRS)](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/) — Chapters on sorting and complexity
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
- [Visualizer for push_swap](https://github.com/o-reo/push_swap_visualizer) — useful for debugging

### AI usage

Claude (Anthropic) was used to:
- Help draft and structure this README.
- Clarify complexity arguments and review algorithm descriptions for accuracy.

All code was written and reviewed by the two authors. AI was not used to generate any source code in this project.
