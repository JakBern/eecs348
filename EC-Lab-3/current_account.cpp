#include "current_account.hpp"
#include <string>

void CurrentAccount::withdraw(unsigned int amount) {
  if (balance - (int)amount < 0 - (int)overdraftAmount) {
    std::cout << "Could not perform withdrawal: insufficient funds\n";
    return;
  }
  balance -= amount;
}


CurrentAccount::CurrentAccount(std::string acctNum, 
              std::string acctHolder, 
              unsigned int amnt,
              unsigned int overdraft) :
              Account(acctNum, acctHolder, amnt, "Current"),
              overdraftAmount(overdraft) {}

std::string CurrentAccount::asString() {
  std::string output = this->Account<CurrentAccount>::asString();
  output += "\tOverdraft Amount: $" + std::to_string(overdraftAmount) + "\n";
  return output;
}