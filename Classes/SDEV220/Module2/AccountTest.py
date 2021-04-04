"""
Jeffrey Harmon
SDEV220
AccountTest.py
Apr. 4, 2021
"""

from Account import Account

# Title
print("Test bank account class.")

# Create account
account = Account(1122, 20000, 4.5)

# Run account methods
account.withdraw(2500)
account.deposit(3000)
account.setID(3345)
account.setBalance(35000)

# Print results
print(f"ID: {account.getID()}")
print(f"Balance: {account.getBalance()}")
print(f"Monthly rate: {account.getMonthlyInterestRate()}")
print(f"Monthly Interest: {account.getMonthlyInterest()}")
