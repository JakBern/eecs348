#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_

#include <iostream>
#include <string>
#include <limits.h>

template <typename Derived>
class Account {
  public:
    void displayDetails();
    virtual void deposit(unsigned int amount);
    virtual void withdraw(unsigned int amount);

    Account(std::string acctNum, std::string acctHolder, unsigned int amnt,     
            std::string acctType);

    template <typename Other>
    friend Derived operator+(Derived& lhs, Account<Other>& rhs)  {
      int prev = rhs.balance;
      rhs.withdraw(300);
      if (prev == rhs.balance) {
        return lhs;
      }
      else {
        lhs.deposit(300);
        return lhs;
      };
    }

    template <typename Other>
    friend std::ostream& operator<<(std::ostream& lhs, 
                                    const Account<Other>& rhs);

    std::string accountNumber;
    std::string accountHolder;
    int balance;
    std::string accountType;

  protected:

    virtual std::string asString();
};

#include "bank_account.hpp"



template <typename Derived>
void Account<Derived>::displayDetails() {
  std::cout << asString();
}

template <typename Derived>
void Account<Derived>::deposit(unsigned int amount) {
  if (amount > (unsigned int)INT_MAX || 
              ((unsigned int)(INT_MAX - balance) < amount)) {
    std::cout << "Cannot make deposit: Amount exceeds deposit limits.\n";
    return;
  }
  balance += amount;
}

template <typename Derived>
void Account<Derived>::withdraw(unsigned int amount) {
  if ((int)amount > balance) {
    std::cout << "Withdrawal could not be made: insufficient funds.\n";
  }
  else {
    balance -= amount;
  }
}

template <typename Derived>
Account<Derived>::Account(std::string acctNum, 
                std::string acctHolder, 
                unsigned int amnt, 
                std::string acctType) : 
                accountNumber(acctNum), 
                accountHolder(acctHolder),
                balance(amnt),
                accountType(acctType)
                {}

template <typename Other>
std::ostream& operator<<(std::ostream& lhs, const Account<Other>& rhs) {
  lhs << rhs.asString();
  return lhs;
}

template <typename Derived>
std::string Account<Derived>::asString() {
  std::string output = "Account details for " + accountType + " Account (ID" 
                      + accountNumber + ")\n";
  output += "\tHolder: " + accountHolder + "\n";
  output += "\tBalance: $" + std::to_string(balance) + ".00\n";
  return output;
}




#endif