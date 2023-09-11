/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:52:14 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/09/11 17:40:33 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cerr << "Usage: ./my_program + positive integer sequences" << std::endl;
		return (1);
	}

	PmergeMe<std::vector<int> >vectSorter;
	std::vector<int> vect;

	vectSorter.sort(vect, argc, argv);

	PmergeMe<std::deque<int> > dequeSorter;
    std::deque<int> deque;

	dequeSorter.sort(deque, argc, argv);

	return (0);
}