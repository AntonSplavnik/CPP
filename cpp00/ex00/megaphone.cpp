/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:31 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/23 21:20:38 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

void toUpper(std::string &output)
{
	for (size_t i = 0; i < output.length(); i++)
		output[i] = std::toupper(output[i]);
}

void concatinateArguments(int ac, char **av, std::string &output)
{
	for (int i = 1; i < ac; i++)
	{
		if (i > 1)
			output += " ";
		output += av[i];
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
		return (0);
	}

	std::string megaphoneMessage;
	std::string &megaphoneMessageRef = megaphoneMessage;

	concatinateArguments(ac, av, megaphoneMessageRef);
	toUpper(megaphoneMessageRef);

	std::cout << megaphoneMessage << std::endl;

	return (0);
}
