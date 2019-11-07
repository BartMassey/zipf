#!/usr/bin/python3

import math
import random

def wordcode(n):
    chars = [chr(ord(c) - ord('0') + ord('a')) for c in str(n)]
    return ''.join(chars)

for _ in range(1000000):
    print(wordcode(random.randrange(100000)))
