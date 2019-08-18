#!/bin/python3

"""
Basic code for learning Python
Problem 18 - Find a string
(https://www.hackerrank.com/challenges/find-a-string/)
"""

def count_substring(string, sub_string):
    n = start = 0
    while (start >= 0):
        start = string.find(sub_string, start, len(string))
        if start >= 0:
            n += 1
            start += 1
    return n

if __name__ == '__main__':
    string = 'ininini' #input().strip()
    sub_string = 'ini' #input().strip()

    count = count_substring(string, sub_string)
    print(count)
