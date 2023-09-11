/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:43:54 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/09/11 17:48:09 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "Wrong number of arguments" << std::endl, 1);
	try
	{
		std::stack<int>	stack;
		std::string	arg = av[1];
		if (RPN(arg, stack))
			return (2);
		return (0);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}