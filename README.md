This project has been created as part of the 42 curriculum by olchacou, ancourt

![42 Badge](https://img.shields.io/badge/42-Project-blue)
![Language](https://img.shields.io/badge/Language-C-brightgreen)
![Norminette](https://img.shields.io/badge/Norminette-passing-success)

---

## Description

**Push Swap** is an advanced sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations while minimizing the number of moves required.

This implementation features **four distinct sorting strategies** with varying time complexities, along with an **adaptive algorithm** that selects the optimal strategy based on input size and disorder level.

### Key Features

- ✅ **LIS + Turk Algorithm** - O(n²) optimized with Longest Increasing Subsequence
- ✅ **Chunk Sort** - O(n√n) divide-and-conquer approach
- ✅ **Radix Sort** - O(n log n) bit-based sorting
- ✅ **Adaptive Strategy** - Intelligent algorithm selection based on disorder metric
- ✅ **Benchmark Mode** - Detailed performance statistics
- ✅ **Bonus Checker** - Validates sorting operations

---

## Performance Targets

### Mandatory Requirements

| Input Size | Minimum | Good | Excellent |
|------------|---------|------|-----------|
| **100 numbers** | < 2000 ops | < 1500 ops | **< 700 ops** |
| **500 numbers** | < 12000 ops | < 8000 ops | **< 5500 ops** |

### Achieved Performance

| Algorithm | 100 numbers | 500 numbers |
|-----------|-------------|-------------|
| **Simple (LIS+Turk)** | ~520 ops  | ~5050 ops |
| **Medium (Chunk)** | ~750 ops | ~6000 ops |
| **Complex (Radix)** | ~700 ops | ~4700 ops  |
| **Adaptive** | ~520 ops  | ~4700 ops  |

---

## Installation

### Prerequisites

- GCC or Clang compiler
- Make
- Unix-based system (Linux/macOS)

### Compilation
```bash
# Clone the repository
git clone [your_repo_url] push_swap
cd push_swap

# Compile mandatory part
make

# Compile bonus (checker)
make bonus

# Clean object files
make clean

# Full clean (remove executables)
make fclean

# Recompile
make re
```

---

## Usage

### Push Swap Program
```bash
# Basic usage
./push_swap 3 2 1 5 4

# With strategy selection
./push_swap --simple 3 2 1 5 4      # Force O(n²) algorithm
./push_swap --medium 3 2 1 5 4      # Force O(n√n) algorithm
./push_swap --complex 3 2 1 5 4     # Force O(n log n) algorithm
./push_swap --adaptive 3 2 1 5 4    # Auto-select (default)

# With benchmark mode
./push_swap --bench --simple 3 2 1 5 4

# Random input
./push_swap $(shuf -i 0-999 -n 100)

# Quoted arguments
./push_swap "3 2 1 5 4"
```

### Checker Program (Bonus)
```bash
# Manual input
./checker 3 2 1
sa
pb
pa
[Ctrl+D]

# With push_swap output
./push_swap 3 2 1 | ./checker 3 2 1

# Expected output: OK or KO
```

---

## Algorithms Explained

### 1. Simple Sort - O(n²) - LIS + Turk

**Concept**: Combines Longest Increasing Subsequence (LIS) detection with the Turk greedy algorithm.

**How it works**:
1. Calculate the LIS in the input
2. Keep LIS elements in stack A (already sorted)
3. Push remaining elements to stack B
4. Use Turk's cost-based insertion to return elements to A
5. Final rotation to position minimum at top

**Advantages**:
- Excellent for small inputs (≤100)
- ~100 operations better than classic Turk
- Still O(n²) complexity (valid for "Simple" requirement)

**Performance**: ~520 operations for 100 numbers

---

### 2. Medium Sort - O(n√n) - Chunk Algorithm

**Concept**: Divide numbers into √n chunks and process them sequentially.

**How it works**:
1. Divide input into √n chunks (5 for 100, 11 for 500)
2. Push each chunk to stack B with smart placement
3. Merge back by repeatedly pushing the maximum from B to A

**Advantages**:
- Good balance between speed and operations
- Predictable performance
- Easy to understand and debug

**Performance**: ~750 operations for 100 numbers, ~6000 for 500

---

### 3. Complex Sort - O(n log n) - Radix Sort

**Concept**: Sort by examining bits from LSB to MSB.

**How it works**:
1. For each bit position (0 to log₂(n)):
   - If bit = 0: push to B
   - If bit = 1: rotate in A
2. Return all from B to A
3. Repeat for next bit

**Advantages**:
- Champion for large inputs (500+)
- Guaranteed O(n log n)
- Consistent performance regardless of input disorder

**Performance**: ~700 operations for 100 numbers, ~4700 for 500

---

### 4. Adaptive Sort - Variable Complexity

**Concept**: Automatically select the best algorithm based on size and disorder.

**Decision tree**:
```
Size ≤ 5        → Hardcoded sorting
Size ≤ 100      → LIS + Turk (always best)
Size > 100:
  disorder < 0.3  → LIS + Turk (low disorder)
  0.3 ≤ d < 0.6   → Chunk Sort (medium disorder)
  disorder ≥ 0.6  → Radix Sort (high disorder)
```

**Disorder metric**: Ratio of inversions to total pairs (0.0 = sorted, 1.0 = reverse sorted)

**Performance**: Automatically achieves best possible for any input

---

## Benchmark Mode

Enable detailed statistics with `--bench` flag:
```bash
$ ./push_swap --bench --adaptive $(shuf -i 0-999 -n 100)
```

**Output** (to stderr):
```
[bench] Disorder: 67.43%
[bench] Strategy: Adaptive → LIS+Turk O(n²) (≤100)
[bench] Total operations: 542
[bench] sa: 12, sb: 8, ss: 3
[bench] pa: 67, pb: 67
[bench] ra: 89, rb: 76, rr: 45
[bench] rra: 98, rrb: 54, rrr: 23
```

---

## Project Structure
```
push_swap/
├── Makefile
├── README.md
│
├── includes/
│   └── push_swap.h           # All function prototypes
│
├── srcs/
│   ├── main.c
│   ├── parsing/              # Input parsing & validation
│   ├── stack/                # Stack data structure
│   ├── operations/           # 11 stack operations
│   ├── algorithms/           # Algorithm dispatchers
│   ├── turk+LIS/             # Turk + LIS implementation
│   ├── chunk/                # Chunk sort implementation
│   ├── radix/                # Radix sort implementation
│   ├── benchmark/            # Statistics & printing
│   ├── metrics/              # Disorder calculation
│   └── utils/                # Error handling & helpers
│
└── bonus/
    ├── checker.c             # Checker main
    ├── checker_ops.c         # Operation execution
    ├── checker_utils.c       # Helpers
    └── get_next_line.*       # Read operations from stdin
```

**Total**: 33 files (28 mandatory + 5 bonus)

---

## Testing

### Automated Tests
```bash
# Quick test
make test

# Bonus test
make test-bonus
```

### Manual Testing
```bash
# Small inputs
./push_swap 3 2 1
./push_swap 5 4 3 2 1

# 100 random numbers
./push_swap $(shuf -i 0-999 -n 100) | wc -l

# 500 random numbers with specific strategy
./push_swap --complex $(shuf -i 0-9999 -n 500) | wc -l

# Verify with checker
ARG=$(shuf -i 0-999 -n 100)
./push_swap $ARG | ./checker $ARG
```

### Expected Results

| Test | Expected |
|------|----------|
| `./push_swap 2 1` | `sa` |
| `./push_swap 1 2 3` | _(no output - already sorted)_ |
| `./push_swap 3 2 1 \| wc -l` | `≤ 3` |
| `100 random \| wc -l` | `< 700` |
| `500 random \| wc -l` | `< 5500` |

---

## Technical Details

### Stack Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack A |
| `sb` | Swap first 2 elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of B to A |
| `pb` | Push top of A to B |
| `ra` | Rotate A (first → last) |
| `rb` | Rotate B (first → last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (last → first) |
| `rrb` | Reverse rotate B (last → first) |
| `rrr` | `rra` and `rrb` simultaneously |

### Complexity Analysis

**LIS Calculation**: O(n²)
- Dynamic programming approach
- Finds longest increasing subsequence

**Turk Algorithm**: O(n²)
- For each element in B: O(n)
- Calculate costs: O(n)
- Find cheapest: O(n)
- Total: n × O(n) = O(n²)

**Chunk Sort**: O(n√n)
- √n chunks
- Process each chunk: O(n)
- Total: √n × O(n) = O(n√n)

**Radix Sort**: O(n log n)
- log₂(n) bits
- Process each bit: O(n)
- Total: log₂(n) × O(n) = O(n log n)

---

##  Error Handling

The program handles all edge cases:

| Error Case | Output | Exit Code |
|------------|--------|-----------|
| No arguments | _(silent)_ | 0 |
| Non-numeric input | `Error\n` | 1 |
| Integer overflow | `Error\n` | 1 |
| Duplicate values | `Error\n` | 1 |
| Invalid operation (checker) | `Error\n` | 1 |

---

## Resources

### Algorithm Theory
- [Longest Increasing Subsequence - GeeksforGeeks](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/)
- [Radix Sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Big-O Notation Guide](https://www.bigocheatsheet.com/)

### 42 Documentation
- [Push Swap Subject](docs/en.subject.pdf)
- https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0 
- https://github.com/alx-sch/push_swap https://github.com/ayogun/push_swap 

- https://42-cursus.gitbook.io/guide/2-rank-02/push_swap

- https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0
- https://www.youtube.com/watch?v=AAwYzYkjNTg

### AI Usage
This project was developed with assistance from AI tools (Claude by Anthropic) for:

- **Debugging**: Identifying edge cases and memory leaks
- **Documentation**: Structuring README 

All code was reviewed, understood, and modified by the developer. AI served as  consulting documentation.

---

## 👨‍💻 Authors

**Anais COURT** - [@ancourt](https://profile.intra.42.fr/users/ancourt)
**Gracieux CHACOUN** - [@olchacou](https://profile.intra.42.fr/users/olchacou)

42 School - Lyon, Auvergne Rhones alpes - 2025

---

## 📜 License

This project is part of the 42 School curriculum and follows their academic policies.


























