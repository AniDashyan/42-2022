#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	std::cout << "index:" << _accountIndex << ";";
	_amount = initial_deposit;
	std::cout << "amount:" << _amount << ";";
	_totalAmount += _amount;
	std::cout << "created" << std::endl;
	_nbAccounts++;
}

Account::Account() {
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
	_nbAccounts--;
}

int	    Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	    Account::getTotalAmount( void ) {
	return _totalAmount;
}


int	    Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	    Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" 
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t now = std::time(0);
    tm* local_time = std::localtime(&now);

    const char* format = "[%Y%m%d_%H%M%S]";
	char formatted_time[20];
    std::strftime(formatted_time, sizeof(formatted_time), format, local_time);
    std::cout << formatted_time << " ";
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += this->_nbDeposits;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		withdrawal = 0;
		std::cout << "withdrawal:refused\n";
		return (0);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += this->_nbWithdrawals;
	return (1);
}

int		Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}