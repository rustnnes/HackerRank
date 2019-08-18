#!/bin/python3

"""
Basic code for learning Python
Problem 9 - Runner-up
(https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/)
"""

def runner_up(l):
    return sorted(list(set(l)))[-2]

if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    print(runner_up(arr))
