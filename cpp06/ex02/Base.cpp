/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:27:52 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/01 12:34:17 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base* generate(void){

	static bool seeded = false;
	if (!seeded) {
		srand(time(0));
		seeded = true;
	}

	switch(rand() % 3){
		case 1: return new A();
		case 2: return new B();
		default: return new C();
	}
}

void identify(Base* p){

	if (dynamic_cast<A*>(p) != NULL){
		std::cout << "A" << std::endl;
		return;
	}
	else if (dynamic_cast<B*>(p) != NULL){
		std::cout << "B" << std::endl;
		return;
	}
	else
		std::cout << "C" << std::endl;

}

void identify(Base& p){

	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(const std::exception& e){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception& e){}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e){}
}
