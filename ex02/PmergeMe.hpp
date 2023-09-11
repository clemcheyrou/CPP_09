/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:09:40 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/09/11 13:50:15 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <ctime>
# include <vector>
# include <deque>

bool isDigit(char *str);

template <typename T>
class PmergeMe
{
	private:
		T				*_elem;
		
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe<T> const &copy);
		~PmergeMe(void);

		PmergeMe 	&operator=(PmergeMe<T> const &rhs);

		int		sort(T &vect, int ac, char **av);
		int		fill(T &vect, int ac, char **av);
		void	print(const T vect);
		void	divide(T &vect, int left, int right);
		void	merge(T &vect, int left, int mid, int right);

};


#endif