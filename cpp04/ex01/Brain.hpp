/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:30:36 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/09 16:38:42 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

	public:

		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void addIdea(const std::string& idea); // Adds to the next free slot
		std::string getIdea(int index) const;  // Still needed for internal use
		void printAllIdeas() const;

		std::string ideas[100];

	private:

		int _ideaCount;
};

#endif
