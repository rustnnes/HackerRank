#!/bin/python3

"""
Basic code for learning Python
Problem 19 - String Validators
(https://www.hackerrank.com/challenges/string-validators/)
"""

def hasAlnum(v):
    ctrl = False
    for c in v:
        if c.isalnum():
            ctrl = True
            break
    return ctrl

def hasAlpha(v):
    ctrl = False
    for c in v:
        if c.isalpha():
            ctrl = True
            break
    return ctrl

def hasLower(v):
    ctrl = False
    for c in v:
        if c.islower():
            ctrl = True
            break
    return ctrl

def hasUpper(v):
    ctrl = False
    for c in v:
        if c.isupper():
            ctrl = True
            break
    return ctrl

def hasDigit(v):
    ctrl = False
    for c in v:
        if c.isdigit():
            ctrl = True
            break
    return ctrl


if __name__ == '__main__':
    s = 'qadois' #input()
    print(hasAlnum(s))
    print(hasAlpha(s))
    print(hasDigit(s))
    print(hasLower(s))
    print(hasUpper(s))
