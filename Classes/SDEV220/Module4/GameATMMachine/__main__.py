"""
Jeffrey Harmon
SDEV220
GameATMMachine.py
Apr. 18, 2021
"""

from Account import Account

# Title
print("Game ATM machine!", end="\n\n")

accounts = []
for i in range(0, 10):
    accounts.append(Account(i + 1, 500.0))

# Get user input
index = 0
choice = 0

while True:
    try:
        index = int(input(f"Enter an account id (1-{len(accounts)}): "))

        if not (0 < index <= len(accounts)):
            break

        account = accounts[index - 1]

        while True:
            print("\n")
            print("Main menu")
            print("1: check balance")
            print("2: withdraw")
            print("3: deposit")
            print("4: exit")
            choice = int(input("Enter a choice: "))

            print("\n")

            if not (0 < choice <= 3):
                break

            if choice == 1:
                print(f"Balance: {account.getBalance()}")
            elif choice == 2:
                account.withdraw(
                    float(input("Enter the amount to withdraw: ")))
            else:
                account.deposit(float(input("Enter the amount to deposit: ")))
    except:
        print("Invalid input. Try again!", end="\n\n")

    print("\n")

# Print results
print("\n\n")
print("Account balances:")

for account in accounts:
    print(f"{account.getID()}: ${account.getBalance()}", end="\n")
