#!/usr/bin/python3
"""
Min operators function
"""


def minOperations(n):
    op = 0
    res = 1
    cp = 0
    while n != res:
        if n % res == 0:
            op += 2
            cp = res
            res += cp
        elif n % res != 0:
            op += 1
            res += cp
    return op
