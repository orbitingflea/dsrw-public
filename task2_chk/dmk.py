#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random
import sys

from testcase.case7 import *
# R = 2
# I = int(1e7)
# N = int(1e7)
# M = int(2e5)
# E = 1

INT_RANGE = 2147483648
RANGE_LIMIT = INT_RANGE >> R

init_keys = random.choices(range(-INT_RANGE, INT_RANGE), k=I)
init_values = random.choices(range(-INT_RANGE, INT_RANGE), k=I)

keys = random.choices(range(-INT_RANGE, INT_RANGE), k=N)
values = random.choices(range(-INT_RANGE, INT_RANGE), k=N)

ranges_left = random.choices(range(-INT_RANGE, INT_RANGE), k=M)
ranges_right = list(map(lambda x: random.randint(
    x, min(INT_RANGE - 1, x + RANGE_LIMIT)), ranges_left))

ed_ranges_left = random.choices(range(-INT_RANGE, INT_RANGE), k=E)
ed_ranges_right = list(map(lambda x: random.randint(
    x, min(INT_RANGE - 1, x + RANGE_LIMIT)), ed_ranges_left))

init_ops = [f'i {key} {value}\n' for key, value in zip(init_keys, init_values)]
insert_ops = [f'i {key} {value}\n' for key, value in zip(keys, values)]
range_ops = [f'r {lvalue} {rvalue}\n' for lvalue,
             rvalue in zip(ranges_left, ranges_right)]
ed_ops = [f'r {lvalue} {rvalue}\n' for lvalue,
          rvalue in zip(ed_ranges_left, ed_ranges_right)]

rand_ops = insert_ops + range_ops
for _ in range(4):
    random.shuffle(rand_ops)
ops = init_ops + rand_ops + ed_ops

with open(sys.argv[1], 'w') as f:
    f.write(f'{I + N + M + E}\n')
    f.writelines(ops)
