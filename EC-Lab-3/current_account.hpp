#ifndef CURRENT_ACCOUNT_H_
#define CURRENT_ACCOUNT_H_

#include "bank_account.hpp"

#include <string>

class CurrentAccount : public Account<CurrentAccount> {
  public:
    virtual void withdraw(unsigned int amount) override;

    CurrentAccount(std::string acctNum, 
                  std::string acctHolder, 
                  unsigned int amnt,
                  unsigned int overdraft);
        
  protected:
    unsigned int overdraftAmount;

    virtual std::string asString() override;
};




#endif