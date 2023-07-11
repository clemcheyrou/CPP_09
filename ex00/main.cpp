/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:45:56 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/11 15:12:41 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Error: could not open file." << std::endl, 1);
	else
	{
		BitcoinExchange btc("data.csv");
		std::ifstream ifs(av[1]);
		if (!ifs)
		{
			std::cerr << "Error: could not open file.\n" << std::endl;
			return ;
		}
		
		std::map<std::string, double> input;
		std::string	str;
		while (std::getline(ifs, str))
		{
			std::istringstream iss(str);
			std::string date;
			double num;
			if (std::getline(iss, date, '|') && iss >> num)
				input[date] = num;
		}
		
		return (0);
	}
}