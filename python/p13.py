#!/bin/python3

"""
Basic code for learning Python
Problem 13 - Tuples
(https://www.hackerrank.com/challenges/python-tuples/)
"""

if __name__ == '__main__':
    n = int(input())
    integer_list = map(int, input().split())

    t = tuple(integer_list)
    print(hash(t))
