/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:49:28 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/07 16:52:12 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void testBasicMateriaUsage() {
	std::cout << "\n[ Test 1: Learn and Use Materias ]" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("Me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("Bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void testInventoryOverflow() {
	std::cout << "\n[ Test 2: Equip More Than 4 Materias ]" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* hero = new Character("Hero");

	int equipCount = 0;
	for (int i = 0; i < 6; ++i) {
		AMateria* m = (i % 2 == 0) ? src->createMateria("ice") : src->createMateria("cure");

		if (equipCount < 4) {
			hero->equip(m);
			equipCount++;
		} else {
			std::cout << "Inventory full. Deleting extra materia.\n";
			delete m; // Prevent memory leak
		}
	}

	ICharacter* target = new Character("Target");

	for (int i = 0; i < 4; ++i) {
		std::cout << "Using materia in slot " << i << ":\n";
		hero->use(i, *target);
	}

	delete target;
	delete hero;
	delete src;
}

void testUnequip() {
	std::cout << "\n[ Test 3: Unequip Materia ]" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* wizard = new Character("Wizard");

	AMateria* ice = src->createMateria("ice");
	wizard->equip(ice);

	wizard->unequip(0);  // Should not delete ice

	// Still responsible for manually deleting it
	delete ice;

	delete wizard;
	delete src;
}

void testInvalidMateriaCreation() {
	std::cout << "\n[ Test 4: Create Unknown Materia Type ]" << std::endl;

	IMateriaSource* src = new MateriaSource();
	AMateria* m = src->createMateria("fire");

	if (!m)
		std::cout << "Unknown materia returned nullptr as expected.\n";

	delete src;
}

void testDeepCopyCharacter() {
	std::cout << "\n[ Test 5: Deep Copy Character ]" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	Character original("Original");
	original.equip(src->createMateria("ice"));

	Character clone = original;

	std::cout << "Original uses slot 0:\n";
	original.use(0, original);

	std::cout << "Clone uses slot 0:\n";
	clone.use(0, clone);

	delete src;
}

int main() {
	testBasicMateriaUsage();
	testInventoryOverflow();
	testUnequip();
	testInvalidMateriaCreation();
	testDeepCopyCharacter();

	std::cout << "\n[ All tests completed successfully ]" << std::endl;
	return 0;
}


/*
int main()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");

	me->equip(tmp);
	tmp = src->createMateria("cure");

	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
} */