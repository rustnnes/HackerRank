#!/bin/python3

"""
Basic code for learning Python
Problem 2 - If-Else
(https://www.hackerrank.com/challenges/py-if-else/)
"""

if __name__ == '__main__':
  n = int(input().strip())
  if n % 2 != 0:
    print("Weird")
  else:
    if n in range(2, 6):
      print("Not Weird")
    elif n in range(6, 21):
      print("Weird")
    else:
      print("Not Weird")
