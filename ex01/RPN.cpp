/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:41:28 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/11 20:00:33 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Constructor" << std::endl;
}

RPN::RPN(RPN const &copy)
{
	*this = copy;
}

RPN::~RPN()
{
	std::cout << "Destructor" << std::endl;
}

RPN& RPN::operator=(RPN const & rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

int	opsum(int result, int nb)
{
	return (result += nb);
}

int	opsub(int result, int nb)
{
	return (result -= nb);	
}

int	opmul(int result, int nb)
{
	return (result *= nb);	
}

int	opdiv(int result, int nb)
{
	return (result /= nb);	
}