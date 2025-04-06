/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:36:08 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/06 15:12:24 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "[ Test 1: Cannot Instantiate Animal Directly ]" << std::endl;
	// AAnimal a;

	std::cout << "\n[ Test 2: Create Dog and Cat as Animal* ]" << std::endl;
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << "\n[ Test 3: Polymorphic Behavior ]" << std::endl;
	dog->makeSound(); // Should output "Dog makes sound"
	cat->makeSound(); // Should output "Cat makes sound"

	std::cout << "\n[ Test 4: Destruction Check ]" << std::endl;
	delete dog;
	delete cat;

	return 0;
}

