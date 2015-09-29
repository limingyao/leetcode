#!/bin/bash

# Tenth Line
# Read from the file file.txt and output the tenth line to stdout.

# Method 1:
# awk 'NR == 10' file.txt

# Method 2:
sed -n '10p' file.txt
