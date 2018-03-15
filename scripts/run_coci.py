#!/usr/bin/env python2
import run_test
import sys
import os

testcase_dir = sys.argv[1]

inputs = []
outputs = []

for name in sorted(os.listdir(testcase_dir)):
    path = os.path.join(testcase_dir, name)
    if ".in" in name:
        inputs.append(path)
    else:
        assert(".out" in name)
        outputs.append(path)

for i, o in zip(inputs, outputs):
    run_test.run_test(i, o)
