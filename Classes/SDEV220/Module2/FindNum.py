"""
Jeffrey Harmon
SDEV220
FindNum.py
Apr. 4, 2021
"""

# Title
print("Divisible by 7, but not 8. Between 200 and 400.")


# Calculate and print results
results = []
for i in range(203, 400, 7):
    if (i % 8 != 0):
        results.append(str(i))
    if (len(results) == 10):
        print(" ".join(results))
        results = []

print(" ".join(results))
