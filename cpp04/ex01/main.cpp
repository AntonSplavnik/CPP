/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:36:08 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/06 15:00:26 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testAnimalArray()
{
	std::cout << "\n[ Test 1: Array of Animals (Cats & Dogs) ]" << std::endl;
	const int size = 4;
	const Animal* animals[size];

	for (int i = 0; i < size; ++i)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
			else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; ++i)
		delete animals[i];
}

void testDeepCopy()
{
	std::cout << "\n[ Test 2: Deep Copy of Dog and Cat ]" << std::endl;
	Dog originalDog;
	originalDog.makeSound();

	Dog copiedDog(originalDog);
	copiedDog.makeSound();

	Cat originalCat;
	originalCat.makeSound();

	Cat copiedCat;
	copiedCat = originalCat;
	copiedCat.makeSound();
}

void testPolymorphism()
{
	std::cout << "\n[ Test 3: Polymorphism Test ]" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

dog->makeSound();
cat->makeSound();

delete dog;
delete cat;
}

int main()
{
	testAnimalArray();
	testDeepCopy();
	testPolymorphism();

	std::cout << "\n[ All tests completed ]\n" << std::endl;
	return 0;
}
