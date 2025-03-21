/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:31 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/21 01:05:31 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

void	ToUpper(std::string &output)
{
	for (size_t i = 0; i < output.length(); i++)
		output[i] = std::toupper(output[i]);
}

void	ConcatinateArguments(int ac, char **av, std::string &output)
{
	for (int i = 1; i < ac; i++)
	{
		output += " ";
		output +=av[i];
	}
}

int	main(int ac, char **av)
{
	std::string megaphoneMessage;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
		return (0);
	}

	std::string &megaphoneMessageRef = megaphoneMessage;

	ConcatinateArguments(ac, av, megaphoneMessageRef);
	ToUpper(megaphoneMessageRef);

	std::cout << megaphoneMessage << std::endl;

	return (0);
}
