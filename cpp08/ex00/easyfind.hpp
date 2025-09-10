/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:58:27 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/10 17:48:28 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

template<typename T>
void easyfind(T& container, int valueToFind){
	typename T::iterator found = std::find(container.begin(), container.end(), valueToFind);
	if(found != container.end()){
			std::cout << *found << std::endl;
	}
	else
		throw std::out_of_range("Element not found");
}

#endif
