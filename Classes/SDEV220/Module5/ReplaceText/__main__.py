"""
Jeffrey Harmon
SDEV220
ReplaceText.py
Apr. 25, 2021
"""

import os

# Title
print("Replace Text")

# Get user input
filename = input("Enter a filename: ")
oldString = input("Enter the old string to be replaced: ")
newString = input("Enter the new string to replace the old string: ")

print()

# Exit if file does not exist
if not os.path.isfile(filename):
    print("File does not exist!")
    exit()

# Open file
file = open(filename, "r+")

# Read and erase file
lines = file.readlines()
file.truncate(0)
file.seek(0)

# Write file
for line in lines:
    file.write(line.replace(oldString, newString))

# Close file
file.close()

print("Done")
