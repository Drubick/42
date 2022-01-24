#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int     Account::getNbAccounts( void ){return(_nbAccounts);}
int     Account::getTotalAmount( void ){return(_totalAmount);}
int     Account::getNbDeposits( void ){return(_totalNbDeposits);}
int     Account::getNbWithdrawals( void ){return(_totalNbWithdrawals);}
int     Account::checkAmount(void)const{return(this->_amount);}
void    Account::_displayTimestamp( void )
{
    char timestamp[19];

    std::time_t time = std::time(NULL);
    std::strftime(timestamp, 19, "[%Y%m%d_%H%M%S] ", std::localtime(&time));
    std::cout << timestamp;
}
void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "Account:" << getNbAccounts() << ";total:" << getTotalAmount()
            <<";deposits:" << getNbDeposits() << "withdrawls:"<< getNbWithdrawals() << "\n";
}

// CONSTRUCTOR
Account::Account( int initial_deposit)
{
    this->_accountIndex = this->_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount += initial_deposit;
    this->_nbAccounts++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created\n";
}

void    Account::makeDeposit(int depposit)
{
    this->_nbDeposits++;
    this->_totalAmount += depposit;
    std::cout <<
}

bool    Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > this->_totalAmount)
    {

        return (false);
    }
    else
        this->_totalAmount -= withdrawal;
    return (true);
}

Account::~Account(void)
{

}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();

    std::cout << "index:" << this->_accountIndex << "amount:" <<this->_amount
                << "deposit:" << this->_nbDeposits << "withdrawaks" << this->_nbWithdrawals << "\n";
}

