/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:31:12 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/27 14:24:48 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain ( std::string level ) {

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcions[])() = {&Harl::dbug, &Harl::info, &Harl::warning,
								  &Harl::error};

	for (int i = 0; i < 4; i++)
		if (level == levels[i]){
			(this->*funcions[i])();
			return ;
		}

}


void Harl::dbug( void ){

	std::cout << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-specialketchup "
			  << " burger. I really do!" << std::endl;
}

void Harl::info( void ) {

	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn't put enough bacon in my burger! "
			  << "If you did, I wouldn't be asking for more!"
			  << std::endl;
}

void Harl::warning( void ) {

	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I've been coming for years, whereas you started working "
			  << "here just last month."
			  << std::endl;
}

void Harl::error( void ) {

	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}