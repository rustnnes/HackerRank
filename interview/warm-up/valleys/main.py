#!/usr/bin/env python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):
    curr_sea_level = 0
    prev_sea_level = 0
    n_valleys = 0
    for unit in s:
        prev_sea_level = curr_sea_level
        curr_sea_level += 1 if (unit == 'U') else -1
        if prev_sea_level < 0 and curr_sea_level < 0:
            n_valleys += 1
    return n_valleys

if __name__ == '__main__':
    n = 8
    s = "UDDDUDUU"
    result = countingValleys(n, s)
    print(result)
