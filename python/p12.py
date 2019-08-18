#!/bin/python3

"""
Basic code for learning Python
Problem 12 - Lists
(https://www.hackerrank.com/challenges/python-lists/)
"""

def action(line, lst):
    ln = line.split()

    if ln[0] == 'print':
        print(lst)
    if ln[0] == 'sort':
        lst.sort()
    if ln[0] == 'pop':
        lst.pop()
    if ln[0] == 'reverse':
        lst.reverse()
    if ln[0] == 'insert':
        lst.insert(int(ln[1]), int(ln[2]))
    if ln[0] == 'append':
        lst.append(int(ln[1]))
    if ln[0] == 'remove':
        lst.remove(int(ln[1]))


if __name__ == '__main__':
    lista = []

    n = int(input())
    for _ in range(n):
        action(input(), lista)

    # inputList = [
    #     'insert 0 5',
    #     'insert 1 10',
    #     'insert 0 6',
    #     'print',
    #     'remove 6',
    #     'append 9',
    #     'append 1',
    #     'sort',
    #     'print',
    #     'pop',
    #     'reverse',
    #     'print'
    # ]
    # for i in range(len(inputList)):
    #     action(inputList[i], lista)
