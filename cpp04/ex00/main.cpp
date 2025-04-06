/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:36:08 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/06 14:31:56 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testAnimalSounds() {
	std::cout << "\n[ Test 1: Polymorphic Sounds ]" << std::endl;

	const Animal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; ++i) {
		std::cout << "Animal[" << i << "] is a " << animals[i]->getType() << " and it says: ";
		animals[i]->makeSound();  // Should call Dog or Cat version
	}

	for (int i = 0; i < 4; ++i)
		delete animals[i];
}

void testDirectCalls() {
	std::cout << "\n[ Test 2: Direct Object Sounds (Non-Polymorphic) ]" << std::endl;

	Dog dog;
	Cat cat;

	dog.makeSound(); // Should call Dog::makeSound
	cat.makeSound(); // Should call Cat::makeSound
}

void testBaseObject() {
	std::cout << "\n[ Test 3: Base Class Behavior ]" << std::endl;

	Animal generic;
	generic.makeSound();  // Should call Animal::makeSound
}

void testWrongAnimalPolymorphism() {
	std::cout << "\n[ Test 4: WrongAnimal Polymorphism (No virtual functions) ]" << std::endl;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "WrongAnimal type: " << wrong->getType() << std::endl;
	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

	wrong->makeSound();     // Expected: WrongAnimal sound
	wrongCat->makeSound();  // ⚠️ Expected: WrongAnimal sound (NOT WrongCat), because no virtual

	delete wrong;
	delete wrongCat;
}

void testWrongCatDirect() {
	std::cout << "\n[ Test 5: Direct WrongCat Call (no base class pointer) ]" << std::endl;

	WrongCat wc;
	wc.makeSound(); // Should call WrongCat::makeSound correctly
}

int main() {
	testAnimalSounds();
	testDirectCalls();
	testBaseObject();
	testWrongAnimalPolymorphism();
	testWrongCatDirect();

	std::cout << "\n[ All tests complete ]" << std::endl;
	return 0;
}

