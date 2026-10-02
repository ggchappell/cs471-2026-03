# cool_lib.py
# Glenn G. Chappell
# 2026-10-02
"""Cool library full of cool stuff.
For CS 471 Fall 2026
"""


def fibo(n):
    """n -> F_n (nth Fibonacci number.

    >>> fibo(0)
    0
    >>> fibo(6)
    8
    >>> f = fibo(7)
    >>> f
    13
    """

    curr = 0
    prev = 1
    for _ in range(n):
        prev, curr = curr, curr + prev

    return curr


if __name__ == "__main__":
    print("RUNNING DOCTESTS for cool_lib.py")
    import doctest
    doctest.testmod()

