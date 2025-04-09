/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/07 16:51:09 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {

	for (int i = 0; i < 4; i++ )
		materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {

	for (int i = 0; i < 4; i++ )
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = 0;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {


	for (int i = 0; i < 4; i++ ) {
		delete materias[i];

		if (other.materias[i]) {
			materias[i] = other.materias[i]->clone();
		}
		else
			materias[i] = 0;
	}

	return (*this);
}

MateriaSource::~MateriaSource() {

	for (int i = 0; i < 4; i++ ) {

		delete materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* input) {
	for (int i = 0; i < 4; ++i) {
		if (!materias[i]) {
			materias[i] = input->clone();
			delete input;
			return;
		}
	}
	delete input;
}

AMateria* MateriaSource::createMateria(const std::string& type) {

	for (int i = 0; i < 4; i++ ) {
		if (materias[i] && (materias[i]->getType() == type))
			return (materias[i]->clone());
	}

	return (0);
}