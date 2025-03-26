/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:30:41 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/26 15:50:48 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {

public :
	Harl();
	~Harl();

	void complain ( std::string level );

private :

	void dbug( void );
	void info( void );
	void warning( void );
	void error( void );

};

#endif