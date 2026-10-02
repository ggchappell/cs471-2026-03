#!/usr/bin/env python3
# my_prog1.py
# Glenn G. Chappell
# 2026-10-02
"""Program that uses cool_lib.py.
For CS 471 Fall 2026
"""


import cool_lib  # For .fibo


def fibo_plus_one(n):
    """n -> 1+F(n) [F(n) is the nth Fibonacci number].

    >>> fibo_plus_one(6)
    9
    """

    return cool_lib.fibo(n) + 1


# Main program
# Call fibo_plus_one.

if __name__ == "__main__":  # Executed if file is being run as program
    arg = 7
    print("Calling fibo_plus_one")
    print(f"Argument: {arg}")
    print(f"Result: {fibo_plus_one(arg)}")

