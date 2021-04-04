"""
Jeffrey Harmon
SDEV220
CheckPassword.py
Apr. 4, 2021
"""


def checkPassword(password):
    valid = True
    numDigits = 0
    numChars = 0

    for val in password:
        if (val.isdigit()):
            numDigits += 1
        elif (val.isalpha()):
            numChars += 1
        else:
            valid = False
            break

    if (numDigits < 3):
        valid = False
    if (numChars < 9):
        valid = False

    return valid


# Title
print("Verify password matches pattern.")

# Get password
password = input("Input a password: ")

# Check password
valid = checkPassword(password)

# Print results
print(f"Your password is {'valid' if valid else 'invalid'}")
