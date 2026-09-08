#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:

    // Constructor
    BankAccount(int accNo, string name, double bal = 0)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    // Deposit method
    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            cout << "Amount deposited successfully!" << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }

    // Withdraw method
    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount withdrawn successfully!" << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Get balance
    double getBalance()
    {
        return balance;
    }

    // Get account number
    int getAccountNumber()
    {
        return accountNumber;
    }

    // Display account information
    virtual void displayAccountInfo()
    {
        cout << "\n-----------------------------" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance        : Rs. " << balance << endl;
    }

    // Virtual interest function
    virtual void calculateInterest()
    {
        cout << "Interest calculation is not available for this account."
             << endl;
    }

    // Virtual destructor
    virtual ~BankAccount()
    {
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:

    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal)
    {
        interestRate = rate;
    }

    // Calculate interest
    void calculateInterest() override
    {
        double interest = getBalance() * interestRate / 100;

        cout << "Interest Rate : " << interestRate << "%" << endl;
        cout << "Interest      : Rs. " << interest << endl;
    }

    // Display information
    void displayAccountInfo() override
    {
        BankAccount::displayAccountInfo();

        cout << "Account Type   : Savings Account" << endl;
        cout << "Interest Rate  : " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:

    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal)
    {
        overdraftLimit = limit;
    }

    // Check overdraft
    void checkOverdraft(double amount)
    {
        if (amount <= getBalance())
        {
            cout << "Withdrawal is within available balance." << endl;
        }
        else if (amount <= getBalance() + overdraftLimit)
        {
            cout << "Withdrawal allowed using overdraft." << endl;
            cout << "Overdraft used : Rs. "
                 << amount - getBalance() << endl;
        }
        else
        {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }

    // Withdraw
    void withdraw(double amount) override
    {
        if (amount > 0 &&
            amount <= getBalance() + overdraftLimit)
        {
            double currentBalance = getBalance();

            // If withdrawal is within balance
            if (amount <= currentBalance)
            {
                BankAccount::withdraw(amount);
            }
            else
            {
                // Withdraw available balance first
                if (currentBalance > 0)
                {
                    BankAccount::withdraw(currentBalance);
                }

                double remaining = amount - currentBalance;

                cout << "Overdraft used: Rs. "
                     << remaining << endl;

                cout << "Amount withdrawn successfully!" << endl;
            }
        }
        else
        {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }

    // Display information
    void displayAccountInfo() override
    {
        BankAccount::displayAccountInfo();

        cout << "Account Type    : Checking Account" << endl;
        cout << "Overdraft Limit : Rs. "
             << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:

    FixedDepositAccount(int accNo, string name, double bal,
                        int months, double rate)
        : BankAccount(accNo, name, bal)
    {
        term = months;
        interestRate = rate;
    }

    // Calculate FD interest
    void calculateInterest() override
    {
        double interest =
            getBalance() * interestRate * term / (100 * 12);

        cout << "Interest Rate : " << interestRate << "%" << endl;
        cout << "Term          : " << term << " months" << endl;
        cout << "Interest      : Rs. " << interest << endl;
        cout << "Maturity Amount: Rs. "
             << getBalance() + interest << endl;
    }

    // Display information
    void displayAccountInfo() override
    {
        BankAccount::displayAccountInfo();

        cout << "Account Type   : Fixed Deposit Account" << endl;
        cout << "Term           : " << term << " months" << endl;
        cout << "Interest Rate  : " << interestRate << "%" << endl;
    }
};

int main()
{
    BankAccount* accounts[100];

    int accountCount = 0;
    int choice;

    cout << "========================================" << endl;
    cout << "       BANKING MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;

    do
    {
        cout << "\n========== MAIN MENU ==========" << endl;
        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Checking Account" << endl;
        cout << "3. Create Fixed Deposit Account" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. Display Account Information" << endl;
        cout << "7. Calculate Interest" << endl;
        cout << "8. Check Overdraft" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            int accNo;
            string name;
            double balance, rate;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> balance;

            cout << "Enter Interest Rate (%): ";
            cin >> rate;

            accounts[accountCount] =
                new SavingsAccount(accNo, name, balance, rate);

            accountCount++;

            cout << "\nSavings Account created successfully!"
                 << endl;

            break;
        }

        case 2:
        {
            int accNo;
            string name;
            double balance, limit;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> balance;

            cout << "Enter Overdraft Limit: ";
            cin >> limit;

            accounts[accountCount] =
                new CheckingAccount(accNo, name, balance, limit);

            accountCount++;

            cout << "\nChecking Account created successfully!"
                 << endl;

            break;
        }

        case 3:
        {
            int accNo;
            string name;
            double balance, rate;
            int months;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Deposit Amount: ";
            cin >> balance;

            cout << "Enter Term (months): ";
            cin >> months;

            cout << "Enter Interest Rate (%): ";
            cin >> rate;

            accounts[accountCount] =
                new FixedDepositAccount(
                    accNo, name, balance, months, rate);

            accountCount++;

            cout << "\nFixed Deposit Account created successfully!"
                 << endl;

            break;
        }

        case 4:
        {
            int accNo;
            double amount;
            bool found = false;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            for (int i = 0; i < accountCount; i++)
            {
                if (accounts[i]->getAccountNumber() == accNo)
                {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;

                    accounts[i]->deposit(amount);

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Account not found!" << endl;
            }

            break;
        }

        case 5:
        {
            int accNo;
            double amount;
            bool found = false;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            for (int i = 0; i < accountCount; i++)
            {
                if (accounts[i]->getAccountNumber() == accNo)
                {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;

                    accounts[i]->withdraw(amount);

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Account not found!" << endl;
            }

            break;
        }

        case 6:
        {
            int accNo;
            bool found = false;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            for (int i = 0; i < accountCount; i++)
            {
                if (accounts[i]->getAccountNumber() == accNo)
                {
                    accounts[i]->displayAccountInfo();

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Account not found!" << endl;
            }

            break;
        }

        case 7:
        {
            int accNo;
            bool found = false;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            for (int i = 0; i < accountCount; i++)
            {
                if (accounts[i]->getAccountNumber() == accNo)
                {
                    // Polymorphism
                    accounts[i]->calculateInterest();

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Account not found!" << endl;
            }

            break;
        }

        case 8:
        {
            int accNo;
            double amount;
            bool found = false;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            for (int i = 0; i < accountCount; i++)
            {
                if (accounts[i]->getAccountNumber() == accNo)
                {
                    CheckingAccount* checking =
                        dynamic_cast<CheckingAccount*>(accounts[i]);

                    if (checking != nullptr)
                    {
                        cout << "Enter withdrawal amount: ";
                        cin >> amount;

                        checking->checkOverdraft(amount);
                    }
                    else
                    {
                        cout << "This is not a Checking Account!"
                             << endl;
                    }

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Account not found!" << endl;
            }

            break;
        }


        case 9:
            cout << "\nThank you for using Banking System!"
                 << endl;
            break;


        default:
            cout << "\nInvalid choice! Please try again."
                 << endl;
        }

    } while (choice != 9);

    for (int i = 0; i < accountCount; i++)
    {
        delete accounts[i];
    }

    return 0;
}