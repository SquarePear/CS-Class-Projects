"""
Jeffrey Harmon
SDEV220
NumberOfUpperCase.py
Apr. 25, 2021
"""


def countUppercase(s, value=0):
    if len(s) == 0:
        return value

    return countUppercase(s[1:], value + (1 if s[0].isupper() else 0))


# Title
print("Count Uppercase Letters")

# Get user input
value = countUppercase(input("Enter a string: "))

print()

# Print result
print(f"There are {value} uppercase letters!")
