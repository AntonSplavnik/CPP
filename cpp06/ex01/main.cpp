/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:07:12 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/30 12:34:57 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){

	Data* data = new Data();

	std::cout << "address of data before serialization:  " << data << std::endl;
	uintptr_t addr = Serializer::serialize(data);
	std::cout << "address of data after serialization:   " << addr << std::endl;
	Data* newData = Serializer::deserialize(addr);
	std::cout << "address of data after deserialization: " << newData << std::endl;

	if(data == newData)
		std::cout << "Success: Addresses match!" << std::endl;
	else
		std::cout << "Error: Addresses don't match!" << std::endl;

	delete data;
	return 0;
}
