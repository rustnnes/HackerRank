#!/bin/python3

"""
Basic code for learning Python
Problem 14 - sWAP cASE
(https://www.hackerrank.com/challenges/swap-case/)
"""

def swap_case(s):
    return s.swapcase()

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
