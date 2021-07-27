#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random
import sys

INT_RANGE = 2147483648
RANGE_LIMIT = INT_RANGE >> 2

N = int(1e7)
M = int(2e5)

keys = random.choices(range(-INT_RANGE, INT_RANGE), k=N)
values = random.choices(range(-INT_RANGE, INT_RANGE), k=N)

ranges_left = random.choices(range(-INT_RANGE, INT_RANGE), k=M)
ranges_right = list(map(lambda x: random.randint(
    x, min(INT_RANGE - 1, x + RANGE_LIMIT)), ranges_left))

insert_ops = [f'i {key} {value}\n' for key, value in zip(keys, values)]
range_ops = [f'r {lvalue} {rvalue}\n' for lvalue, rvalue in zip(ranges_left, ranges_right)]

ops = insert_ops + range_ops
random.shuffle(ops)

with open(sys.argv[1], 'w') as f:
    f.write(f'{N + M}\n')
    f.writelines(ops)
