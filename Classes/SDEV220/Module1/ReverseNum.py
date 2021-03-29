"""
Jeffrey Harmon
SDEV220
ReverseNum.py
Mar. 28, 2021
"""

# Get user input
num = str(int(input("Enter a five digit integer: ")))

# Verify length
if (len(num) != 5):
    print("Invalid input!")
    exit()

# Calculate result
result = int(num[2] + num[1] + num[3] + num[0] + num[4])

# Print result
print("The new number is", result)
