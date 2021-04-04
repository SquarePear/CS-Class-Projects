"""
Jeffrey Harmon
SDEV220
PrintTaxTable.py
Apr. 4, 2021
"""


def computeTax(status, taxableIncome):
    tax = 0
    if status == 0:  # Compute tax for single filers
        if taxableIncome <= 8350:
            tax = taxableIncome * 0.10
        elif taxableIncome <= 33950:
            tax = 8350 * 0.10 + (taxableIncome - 8350) * 0.15
        elif taxableIncome <= 82250:
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + \
                (taxableIncome - 33950) * 0.25
        elif taxableIncome <= 171550:
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + \
                (82250 - 33950) * 0.25 + (taxableIncome - 82250) * 0.28
        elif taxableIncome <= 372950:
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + \
                (82250 - 33950) * 0.25 + (171550 - 82250) * 0.28 + \
                (taxableIncome - 171550) * 0.33
        else:
            tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + \
                (82250 - 33950) * 0.25 + (171550 - 82250) * 0.28 + \
                (372950 - 171550) * 0.33 + (taxableIncome - 372950) * 0.35
    elif status == 1:  # Compute tax for married file jointly
        print("Left as exercise")
    elif status == 2:  # Compute tax for married separately
        print("Left as exercise")
    elif status == 3:  # Compute tax for head of household
        print("Left as exercise")
    else:
        print("Error: invalid status")
        exit()

    return tax


# Title
print("Calculate taxes.")


# Prompt the user to enter filing status
status = int(input(
    "(0-single filer, 1-married jointly,\n" +
    "2-married separately, 3-head of household)\n" +
    "Enter the filing status: "))

# Prompt the user to enter taxable income
income = float(input("Enter the taxable income: "))

tax = computeTax(status, income)

# Display the result
print("Tax is", format(tax, ".2f"))
