/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:42:33 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/23 20:11:17 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iostream>
#include <ctime>
#include <iomanip>

/* c++ -std=c++98 -Wall -Wextra -Werror tests.cpp Account.cpp -o my_test */

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {

	this->_accountIndex = _nbAccounts;
	_nbAccounts++;

	this->_amount += initial_deposit;
	_totalAmount += initial_deposit;

	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";"
			  << "created" << std::endl;
};

Account::~Account( void ) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";"
			  << "closed" << std::endl;
};

int	Account::getNbAccounts( void ) {
	return(_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}
int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::makeDeposit( int deposit ) {

	int p_amount = this->_amount;

	this->_nbDeposits++;
	_amount += deposit;

	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	int p_amount = this->_amount;

	if (p_amount - withdrawal < 0) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"
				  << "p_amount:" << p_amount << ";"
				  << "withdrawal:refused"
				  << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "withdrawal:" << withdrawal << ";"
			  << "amount:" << _amount << ";"
			  << "nb_withdrawals:" << this->_nbWithdrawals
			  << std::endl;

	return (true);
}

void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
	<< "total:" << _totalAmount << ";"
	<< "deposits:" << _totalNbDeposits << ";"
	<< "withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "deposits:" << this->_nbDeposits<< ";"
	<< "withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}

void	Account::_displayTimestamp( void ) {

	std::time_t now = std::time(NULL);
	std::tm* timeinfo = std::localtime(&now);

	std::cout << '['
			  << (timeinfo->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') << timeinfo->tm_mon + 1
			  << std::setw(2) << std::setfill('0') << timeinfo->tm_mday
			  << '_'
			  << std::setw(2) << std::setfill('0') << timeinfo->tm_hour
			  << std::setw(2) << std::setfill('0') << timeinfo->tm_min
			  << std::setw(2) << std::setfill('0') << timeinfo->tm_sec
			  << "] ";
}
