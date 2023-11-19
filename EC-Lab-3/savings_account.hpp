#ifndef SAVINGS_ACCOUNT_H_
#define SAVINGS_ACCOUNT_H_

#include "bank_account.hpp"

#include <string>

class SavingsAccount : public Account<SavingsAccount> {
  public:
    virtual void withdraw(unsigned int amount) override;

    SavingsAccount(std::string acctNum, 
                  std::string acctHolder, 
                  unsigned int amnt,
                  float intRate);

  protected:
    float interestRate;

    virtual std::string asString() override;
};




#endif