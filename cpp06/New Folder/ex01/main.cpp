/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:07:12 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/03 13:56:08 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){

	Data* data = new Data();
	data->floatValue = 42.42f;
	data->intValue = 42;
	data->stringValue = "test string";

	std::cout << "float:   " << data->floatValue << std::endl;
	std::cout << "int:     " << data->intValue <<  std::endl;
	std::cout << "string:  " << data->stringValue << std::endl;

	std::cout << "\naddress of data before serialization:  " << data << std::endl;

	uintptr_t addr = Serializer::serialize(data);
	std::cout << "address of data after serialization:   " << addr << std::endl;

	Data* newData = Serializer::deserialize(addr);
	std::cout << "address of data after deserialization: " << newData << std::endl;

	if(data == newData)
		std::cout << "Success: Addresses match!" << std::endl;
	else
		std::cout << "Error: Addresses don't match!" << std::endl;

	std::cout << "\nfloat:   " << newData->floatValue << std::endl;
	std::cout << "int:     " << newData->intValue <<  std::endl;
	std::cout << "string:  " << newData->stringValue << std::endl;

	delete data;
	
	return 0;
}
