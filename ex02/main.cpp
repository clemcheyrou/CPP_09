/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:52:14 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/08/09 19:55:27 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	checkInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		for (int j = 0; av[i][j] != '\0'; j++)
			if (!std::isdigit(av[i][j]))
				return (0);
	return (1);
}

int main(int ac, char **av)
{
	if (ac < 2 || !checkInput(ac, av))
	{
		std::cout << "Error: Wrong arguments" << std::endl;
		return (1);
	}
	//Print arguments
	for (int i = 1; i < ac; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;

	PmergeMe pmergeme(ac - 1, av);
	
}