#include "Account.hpp"

static int Account::getNbAccounts(void) {
	return  this->_nbAccounts;
}

static int Account::getTotalAmount(void) {
	return  this->_totalAmount;
}

static int Account::getNbDeposits(void) {
	return this->_totalNbDeposits;
}

static int Account::getNbWithdrawals(void) {
	return this->_totalNbWithdrawals;
}

