"""
Jeffrey Harmon
SDEV220
SortThreeNum.py
Apr. 4, 2021
"""

# Define functions


def displayIncreasing(arr):
    print(" ".join(map(str, sorted(arr))))


def displayDecreasing(arr):
    print(" ".join(map(str, sorted(arr, reverse=True))))


# Title
print("Sort numbers in increasing and decreasing orders.")

# Get user input
nums = []
for i in range(0, 3):
    nums.append(float(input(f"Enter num #{i+1}: ")))

# Print results
displayIncreasing(nums)
displayDecreasing(nums)
