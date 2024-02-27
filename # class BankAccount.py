class BankAccount:
    def __init__(self, account_number, customer_name, date_of_opening):
        self.account_number = account_number
        self.customer_name = customer_name
        self.date_of_opening = date_of_opening
        self.balance = 0.0

    def deposit(self, amount):
        """
        Deposits the given amount into the account.
        Returns the amount deposited.
        """
        if amount > 0:
            self.balance += amount
            return amount
        else:
            return 0.0

    def withdraw(self, amount):
        """
        Withdraws the given amount from the account.
        Returns the withdrawn amount if sufficient balance is available,
        otherwise returns "Insufficient balance".
        """
        if amount <= self.balance:
            self.balance -= amount
            return amount
        else:
            return "Insufficient balance"

    def check_balance(self):
        """
        Prints the current balance.
        """
        print(f"Current balance for account {self.account_number}: ${self.balance:.2f}")

    def customer_details(self):
        """
        Prints customer details: name, account number, date of opening, and balance.
        """
        print(f"Customer Name: {self.customer_name}")
        print(f"Account Number: {self.account_number}")
        print(f"Date of Opening: {self.date_of_opening}")
        print(f"Current Balance: ${self.balance:.2f}")


# Example usage:
if __name__ == "__main__":
    account1 = BankAccount(account_number="123456", customer_name="Walter Nzai", date_of_opening="2024-02-27")
    account1.deposit(1000)
    account1.withdraw(500)
    account1.check_balance()
    account1.customer_details()


