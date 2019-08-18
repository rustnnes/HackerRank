#!/bin/python3

"""
Basic code for learning Python
Problem 15 - String Split and Join
(https://www.hackerrank.com/challenges/python-string-split-and-join/)
"""

def split_and_join(line):
    return '-'.join(line.split())

if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)
