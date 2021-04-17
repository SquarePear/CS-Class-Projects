"""
Jeffrey Harmon
SDEV220
Account.py
Apr. 4, 2021
"""


class Account:
    ID = 0
    balance = 0.0
    annualInterestRate = 0.0

    def __init__(self, ID=0, balance=100.0, annualInterestRate=0.0):
        self.ID = ID
        self.balance = balance
        self.annualInterestRate = annualInterestRate

    def getID(self):
        return self.ID

    def getBalance(self):
        return self.balance

    def getAnnualInterestRate(self):
        return self.annualInterestRate

    def setID(self, ID):
        self.ID = ID

    def setBalance(self, balance):
        self.balance = balance

    def setAnnualInterestRate(self, annualInterestRate):
        self.annualInterestRate = annualInterestRate

    def getMonthlyInterestRate(self):
        return self.annualInterestRate / 12

    def getMonthlyInterest(self):
        return self.balance * self.getMonthlyInterestRate() / 100

    def deposit(self, amount):
        if (amount > 0):
            self.balance += amount

    def withdraw(self, amount):
        if (amount > 0):
            self.balance -= amount
