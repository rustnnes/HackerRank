#!/bin/python3

"""
Basic code for learning Python
Problem 17 - Mutations
(https://www.hackerrank.com/challenges/python-mutations/)
"""

def mutate_string(string, position, character):
    return string[:position] + character + string[position+1:]

if __name__ == '__main__':
    s = input()
    i, c = input().split()
    s_new = mutate_string(s, int(i), c)
    print(s_new)
