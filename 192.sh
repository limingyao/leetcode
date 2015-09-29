#!/bin/bash

# Word Frequency

# Read from the file words.txt and output the word frequency list to stdout.

# Method 1:
# awk '{for(i=1;i<=NF;i++) {count[$i]++}} END {for(i in count) {print i,count[i]}}' words.txt | sort -nr -k 2

# Method 2:
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -rn | awk '{print $2,$1}'
