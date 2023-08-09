/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:33:48 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/08/09 20:28:01 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <map>
#include <deque>
#include <sstream>
#include <ctime>
#include <iterator>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>

class PmergeMe
{
	private:
	std::multimap<int, int> pairs;
	std::deque<int> sortMax ;
	std::deque<int> sortMin ;

	public:
	PmergeMe();
	PmergeMe(int ac, char **av);
	PmergeMe(PmergeMe const & copy);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const & rhs);

};

#endif