#include "savings_account.hpp"

#include <string>
#include <sstream>
#include <iomanip>

void SavingsAccount::withdraw(unsigned int amount) {
  if (balance - (int)amount < 100) {
    std::cout << "Could not make withdrawal: insufficient funds.\n";
  }
  else {
    balance -= amount;
  }
}


SavingsAccount::SavingsAccount(std::string acctNum, 
              std::string acctHolder, 
              unsigned int amnt,
              float intRate) : 
              Account(acctNum, acctHolder, amnt, "Savings"),
              interestRate(intRate) {}


std::string SavingsAccount::asString() {
  std::string output = this->Account<SavingsAccount>::asString();
  std::stringstream rate;
  rate << std::fixed << std::setprecision(2) << interestRate * 100.f;
  output += "\tInterest Rate: " + rate.str() + "%\n";
  return output;
}