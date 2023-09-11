/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:02:19 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/09/11 14:53:27 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	isDigit(char *str)
{
	int	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i])
		return (true);
	return (false);
}

template <typename T>
PmergeMe<T>::PmergeMe() : _elem(new T)
{
    std::cout << "Constructor called" << std::endl;
}

template <typename T> 
PmergeMe<T>::~PmergeMe(void)
{
	std::cout << "Destructor called" << std::endl;
	delete _elem;
	return;
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe<T> const &copy)
{
	std::cout << "Constructor copy called" << std::endl;
	*this = copy;
	return;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(PmergeMe<T> const &rhs)
{
	std::cout << "Operator assignation" << std::endl;
	if (this != &rhs)
		*_elem = *rhs._elem;
	return (*this);
}

template <typename T>
int	PmergeMe<T>::sort(T &container, int ac, char **av)
{
	std::clock_t	start = clock();
	if (fill(container, ac, av))
		return (2);

	std::cout << "UNSORT : ";
	print(container);

	divide(container, 0, container.size() - 1);
	std::cout << "SORT : ";
	print(container);
	double time = 1000000.0 * (clock() - start) / CLOCKS_PER_SEC;
	std::cout << "[" << time << "]" << " ms" << std::endl << std::endl;
	return (0);
}

template <typename T>
int	PmergeMe<T>::fill(T &container, int ac, char **av)
{
	int	number;

	for (int i = 1; i < ac; i++)
	{
		std::istringstream	iss(av[i]);
		if (isDigit(av[i]) && iss >> number && number >= 0)
			container.push_back(number);
		else
			return (std::cerr << av[i] << " : is not a (+) integer" << std::endl, 1);
	}
	return (0);
}

template <typename T>
void	PmergeMe<T>::print(const T container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

}

template <typename T>
void	PmergeMe<T>::divide(T &container, int left, int right)
{
	if (left < right)
	{
		int	mid = (left + right) / 2;
		divide(container, left, mid);
		divide(container, mid + 1, right);
		merge(container, left, mid, right);
	}
}

template <typename T>
void	PmergeMe<T>::merge(T &container, int left, int mid, int right)
{
	int	leftSize = mid - left + 1;
	int	rightSize = right - mid;

	T	leftContainer(leftSize);
	T	rightContainer(rightSize);

	for (int i = 0; i < leftSize; i++)
		leftContainer[i] = container[left + i];
	for (int i = 0; i < rightSize; i++)
		rightContainer[i] = container[mid + i + 1];

	int	i = 0, j = 0, k = left;
	while (i < leftSize && j < rightSize)
	{
		if (leftContainer[i] < rightContainer[j])
			container[k] = leftContainer[i++];
		else
			container[k] = rightContainer[j++];
		k++;
	}

	while (i < leftSize)
		container[k++] = leftContainer[i++];
	while (j < rightSize)
		container[k++] = rightContainer[j++];
}
