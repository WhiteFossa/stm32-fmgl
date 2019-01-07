#!/usr/bin/env python3

import sys

def reverse(x, n):
    result = 0
    for i in range(n):
        if (x >> i) & 1: result |= 1 << (n - 1 - i)
    return result

# Source bytes
sourceBytes = sys.argv[1]

# Split by bytes
splittedBytes = sourceBytes.split()

for chunk in splittedBytes:
    # Cleared byte
    clearedByte = chunk.strip().replace(",", "")
    
    originalValue = int(clearedByte, 16)
    
    convertedValue = reverse(originalValue, 8)
    
    
    sys.stdout.write("0x%0.2X, " % convertedValue)

