"""
Jeffrey Harmon
SDEV220
DisplayPyramid.py
Apr. 4, 2021
"""

# Title
print("Pyramid Time")

# Get user input
height = int(input("Enter the number of lines (1 <= x <= 15): "))

# Print output
for i in range(1, height + 1):
    line = ""
    for j in range(i, 1, -1):
        line += f"{j} "

    line += "1"

    for j in range(1, i):
        line += f" {j + 1}"
    print(" " * (height - i) * 2 + line)

for i in range(height, 0, -1):
    line = ""
    for j in range(i, 1, -1):
        line += f"{j} "

    line += "1"

    for j in range(1, i):
        line += f" {j + 1}"
    print(" " * (height - i) * 2 + line)
