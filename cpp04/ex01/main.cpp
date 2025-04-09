/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:36:08 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/09 16:39:54 by asplavni         ###   ########.fr       */
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
	std::cout << "\n[ Test 2: Deep Copy Test: Dog ]\n" << std::endl;

	{
	Dog original;
	original.addIdea("I want a bone!");
	std::cout << "\nOriginal Dog's ideas:" << std::endl;
	original.printIdeas();
	std::cout << std::endl;

	Dog copy(original);  // Should perform deep copy
	std::cout << "\nCopied Dog's ideas after copy:" << std::endl;
	copy.printIdeas();

	original.addIdea("Changed my mind, chasing a cat now!\n");
	std::cout << "\nOriginal Dog after modification:" << std::endl;
	original.printIdeas();

	std::cout << "Copied Dog should remain unchanged:" << std::endl;
	copy.printIdeas();
	std::cout << std::endl;
	}

	std::cout << "\n[ Test 3: Deep Copy Test: Cat ]\n" << std::endl;
	{
	Cat original;
	original.addIdea("Time to nap!");
	std::cout << "\nOriginal Cat's ideas:" << std::endl;
	original.printIdeas();
	std::cout << std::endl;

	Cat copy;
	copy = original;  // Should perform deep copy
	std::cout << "\nCopied Cat's ideas after assignment:" << std::endl;
	copy.printIdeas();

	original.addIdea("Wait... knock stuff off the shelf instead!");
	std::cout << "\nOriginal Cat after modification:" << std::endl;
	original.printIdeas();

	std::cout << "\nCopied Cat should remain unchanged:" << std::endl;
	copy.printIdeas();
	std::cout << std::endl;
	}
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
