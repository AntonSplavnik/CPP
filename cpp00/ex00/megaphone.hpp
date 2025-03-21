/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:36 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/21 09:33:32 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_HPP
#define MEGAPHONE_HPP

#include <iostream>
#include <string>
#include <cctype>

void	ToUpper(std::string &output);
void	ConcatinateArguments(int ac, char **av, std::string &output);

#endif
