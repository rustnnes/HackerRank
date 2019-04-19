#!/usr/bin/env python3

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
  qty = 0
  scks = ar
  while len(scks) > 1:
    p = scks[0]
    for x in range(1, len(scks)):
      if scks[x] == p:
        qty += 1
        del scks[x]
        scks = scks[1 : len(scks)]
        break
      elif (x+1) == len(scks):
        scks = scks[1 : len(scks)]
  return qty

if __name__ == "__main__":
  n = 9
  ar = [10, 20, 20, 10, 10, 30, 50, 10, 20]
  result = sockMerchant(n, ar)
  print(result)
