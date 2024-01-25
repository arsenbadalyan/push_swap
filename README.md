# Push Swap

Push Swap is a sorting algorithm project implemented in C. It aims to sort a list of integers by manipulating two stacks according to a set of predefined rules.

## Project Description

The Push Swap program takes a list of integers as input arguments and sorts them using two stacks, stack A and stack B. The program outputs a series of operations that, when executed in the specified order, result in a sorted list.

The following operations are permitted:
- `sa`: Swap the first two elements of stack A.
- `sb`: Swap the first two elements of stack B.
- `ss`: Swap the first two elements of both stacks A and B simultaneously.
- `pa`: Push the first element of stack B to stack A.
- `pb`: Push the first element of stack A to stack B.
- `ra`: Rotate all elements of stack A upwards by one. The first element becomes the last.
- `rb`: Rotate all elements of stack B upwards by one. The first element becomes the last.
- `rr`: Rotate all elements of both stacks A and B upwards by one.
- `rra`: Rotate all elements of stack A downwards by one. The last element becomes the first.
- `rrb`: Rotate all elements of stack B downwards by one. The last element becomes the first.
- `rrr`: Rotate all elements of both stacks A and B downwards by one.

The goal is to sort the list in the fewest possible operations.

## Usage

To use the Push Swap program, `make` it and execute it with a list of integers as arguments:

./push_swap 4 67 1 8


The program will output a series of operations required to sort the list.

## Bonus Features

The Push Swap program includes bonus features to determine if a given list of integers can be sorted with the provided operations and whether stack B is empty after sorting.

## Contributors

- [Arsen Badalyan](https://github.com/arsenbadalyan)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
