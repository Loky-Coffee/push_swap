# Push_Swap Project

This is my solution to the "push_swap" project at 42Heilbronn. The goal of this project is to sort a list of numbers using a limited set of stack operations, implemented with arrays.

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Sorting Algorithm](#sorting-algorithm)
- [Performance](#performance)
- [Contributing](#contributing)
- [License](#license)

## Introduction

In this project, I have implemented a sorting algorithm using arrays and stack operations to efficiently sort a list of numbers. The algorithm performs the following steps:

1. Input Validation: The program accepts input either as a string of numbers or as multiple arguments. It can handle tabs instead of spaces and accepts the plus and minus operators, with each number indexed based on its rank.

2. Chunk Division: The input numbers are divided into chunks based on the total number of elements. The number of chunks varies depending on the input size.

3. Initial Sorting: The chunks are sorted in descending order and moved to Stack B, with the largest five numbers kept in Stack A.

4. Sorting Algorithm: The remaining sorting process is done using a custom sorting algorithm implemented in the code.

## Getting Started

To compile the push_swap program, use the provided Makefile. Run:
make

This will generate the `push_swap` executable.

## Usage

To sort a list of numbers, use the `push_swap` project at 42Heilbronn. executable as follows: 

./push_swap [list of numbers]


For example:

./push_swap "3 1 4 2 5"
or
./push_swap 3 1 4 2 5


This will output a series of stack operations to sort the list.

## Sorting Algorithm

The custom sorting algorithm employed in this project is based on the following principles:

- The algorithm identifies whether the next required number can be reached from the top or bottom of Stack B.
- It rotates Stack B to bring the desired number closer while pushing appropriate numbers from Stack A to the bottom.

The algorithm is designed to minimize the number of operations required to sort the list efficiently.

## Performance

Performance statistics for different input sizes:

- Best Case (e.g., already sorted list):
  - 100 numbers: 498 operations
  - 500 numbers: 4220 operations
    
- Average Case:
  - 100 numbers: 560 operations
  - 500 numbers: 4450 operations
    
- Worst Case:
  - 100 numbers: 602 operations
  - 500 numbers: 4620 operations
    
## Contributing

Contributions and suggestions for improvements are welcome. If you'd like to collaborate or provide feedback, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

