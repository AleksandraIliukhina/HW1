Power Digit Sum

This program calculates a number `a` raised to the power of `b` and then finds the sum of all digits of the result.
The program takes two integers as command-line arguments:
- `a` — the base
- `b` — the exponent

For example, if the input is 2 and 15:
2^15 = 32768
Sum Of Digits: 26

The program also checks whether the user's input meets the requirements necessary for the code to run and shows an error message if the input is invalid. Furthermore, the program verifies whether the result of raising number a to the power of b exceeds the maximum value, which is the maximum of unsigned long lonh int.

Makefile

The `Makefile` is used to compile the C++ program automatically. It contains one target called `all`:

all:
	g++ power-digit-sum.cpp -o pds
