/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:02:19 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/08/09 20:31:09 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int ac, char **av)
{
	for (int i = 1; i <= ac; i++)
	{
		if (ac % 2 == 0 || (ac % 2 != 0 && i != ac))
		{
			pairs.insert(std::pair<int, int>(atoi(av[i]), atoi(av[i + 1])));
			i++;
		}
		else
			pairs.insert(std::pair<int, int>(atoi(av[i]), -1));
	}

	for (std::multimap<int, int>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}

	int min = INT_MAX;
	
	for (std::multimap<int, int>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it != pairs.end())
		{
			if (std::max(it->first,it->second) < min)
				min = std::min(it->first,it->second);
			sortMax.push_back(std::max(it->first,it->second));
			sortMin.push_back(std::min(it->first,it->second));
		}
		else
			sortMax.push_back(it->first);
	}
	sortMax.push_front(min);

	for (std::deque<int>::iterator it = sortMax.begin(); it != sortMax.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);
}