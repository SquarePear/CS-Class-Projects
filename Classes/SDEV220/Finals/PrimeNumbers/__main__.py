"""
Jeffrey Harmon
SDEV220
PrimeNumbers.py
May. 16, 2021
"""

from Stack import Stack
import math

# Test if prime


def isPrime(num: int) -> bool:
    if num <= 1:
        return False
    if num <= 3:
        return True

    # Loop through numbers up to sqrt(num) + 1
    # Once i reaches that point, it would just be repeating itself
    for i in range(2, math.ceil(math.sqrt(num)) + 1):
        # Return false if num is evenly divisible by i
        if num % i == 0:
            return False

    # Return true if wasn't divisible by anything
    return True


# Title
print("50 Prime Numbers - Decending")

# Initialize stack
stack = Stack()

# Calculate first 50 prime numbers
i = 1
while stack.getSize() < 50:
    # Add to stack if prime
    if isPrime(i):
        stack.push(i)

    # Increment counter
    i += 1

# Print all numbers in decending order
while not stack.isEmpty():
    print(stack.pop(), end=" ")
