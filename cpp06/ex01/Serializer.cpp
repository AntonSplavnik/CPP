/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:30:34 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/30 12:16:29 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

	uintptr_t Serializer::serialize(Data* ptr){

		uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
		return addr;
	}

	Data* Serializer::deserialize(uintptr_t raw){

		Data* data = reinterpret_cast<Data*>(raw);
		return data;
	}
