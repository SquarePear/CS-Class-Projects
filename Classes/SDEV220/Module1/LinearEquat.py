"""
Jeffrey Harmon
SDEV220
LinearEquat.py
Mar. 28, 2021
"""

# Title
print("Solve linear equation")
print("ax + by = e")
print("cx + dy = f")

# Get input
a, b, c, d, e, f = eval(input("Enter a, b, c, d, e, f: "))

# Calculate results
x = (e * d - b * f) / (a * d - b * c)
y = (a * f - e * c) / (a * d - b * c)

# Print results
print("x is", x, "and y is", y)

# Print input if x - y = 0
if (x - y == 0):
    print(a, b, c, d, e, f)
