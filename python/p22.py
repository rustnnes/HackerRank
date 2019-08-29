#!/bin/python3

"""
Basic code for learning Python
Problem 22 - Designer Door Mat
(https://www.hackerrank.com/challenges/designer-door-mat/)
"""

if __name__ == '__main__':
    l = input().split()
    m = int(l[0])
    n =  m * 3

    lines = []

    above_center_line = (m // 2)

    for i in range(1, above_center_line+1):
        qto = ((n // 2) - (3 * i)) + 2
        lines.append('-' * qto + '.|.' * ((2 * i) - 1) + '-' * qto)


    print(*lines, sep='\n')
    print( ((n - 7) // 2) * '-'  + 'WELCOME'  + ((n - 7) // 2) * '-')
    lines.reverse()
    print(*lines, sep='\n')
