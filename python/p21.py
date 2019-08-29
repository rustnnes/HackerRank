#!/bin/python3

"""
Basic code for learning Python
Problem 21 - Text Wrap
(https://www.hackerrank.com/challenges/text-wrap/)
"""

import textwrap

def wrap(string, max_width):
    return textwrap.fill( textwrap.dedent(string) , width=max_width)

if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)
