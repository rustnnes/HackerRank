#!/bin/python3

"""
Basic code for learning Python
Problem 6 - Function (Leap year)
(https://www.hackerrank.com/challenges/write-a-function/)
"""

def is_leap(year):
  return (year % 4 == 0) and ((year % 100 != 0) or (year % 400 == 0))

if __name__ == '__main__':
  year = int(input())
  print(is_leap(year))
