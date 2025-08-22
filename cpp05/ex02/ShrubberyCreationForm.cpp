/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:19:58 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/22 15:38:52 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string formTarget)
	:AForm("ShrubberyCreationForm", 145, 137), _formTarget(formTarget){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:AForm(other), _formTarget(other._formTarget){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
		if (this != &other) {
	// Can't call AForm::operator= because it's private
	// Can't assign const members anyway
	// Only non-const members could be assigned:
	// _formTarget = other._formTarget;  // But _formTarget is const too!
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getUniqueFilename() const {

	std::string fileName = _formTarget + "_shrubbery.txt";
	std::ifstream test(fileName.c_str());

	short counter = 1;
	while(test.good()){
		test.close();

		std::stringstream ss;
		ss << _formTarget << "_shrubbery(" << counter << ").txt";
		fileName = ss.str();

		test.open(fileName.c_str());
		counter++;
	}
	test.close();

	return fileName;
}


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const{

	requiermentsCheck(executor);

	std::string tree =
	"       *\n"
	"      /|\\\n"
	"     /*|O\\\n"
	"    /*/|\\*\\\n"
	"   /X/O|*\\X\\\n"
	"  /*/X/|\\X\\*\\\n"
	" /O/*/X|*\\O\\X\\\n"
	"/*/O/X/|\\X\\O\\*\\\n"
	"       ||\n"
	"       ||\n"
	"    ___||___\n";

	std::string fileName  = getUniqueFilename();
	std::ofstream file(fileName.c_str());
	if(file.is_open()){
		file << tree << std::endl;
		file.close();
	}
	else
		std::cerr << "Error could not create file " << fileName << std::endl;
}
