#!/bin/python3

"""
Basic code for learning Python
Problem 10 - Nested lists
(https://www.hackerrank.com/challenges/nested-list/)
"""

if __name__ == '__main__':
    students = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        students.append([name, score])

    lowest2nd = sorted( list( set( [student[1] for student in students] ) ) )[1]

    print(
        '\n'.join(
            sorted([student[0] for student in students if student[1] == lowest2nd])
        )
    )
