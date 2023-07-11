/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:47:15 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/11 16:10:20 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//TODO: Gerer les cas d'erreur du fichier csv
BitcoinExchange::BitcoinExchange(std::string file)
{
	std::ifstream ifs(file.c_str());
    if (!ifs)
	{
		std::cerr << "Error: could not open file.\n" << std::endl;
		return ;
	}
	std::string	str;
    while (std::getline(ifs, str))
	{
        std::istringstream iss(str);
        std::string date;
        double num;
        if (std::getline(iss, date, ',') && iss >> num)
			_csv[date] = num;
		else
			std::cout << "this line: " << str << " has no comma or bitcoin is not a number" << std::endl;
    }
	ifs.close();
	return ;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &copy )
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

double 	BitcoinExchange::getBitcoinPrice(std::string const & date) const
{
	if (_csv.empty()) {
		std::cerr << "Error: empty price database.\n";
		return (-1);
	}
		
	std::map<std::string, double>::const_iterator it = _csv.find(date);
	if (it == _csv.end())
	{
		it = _csv.lower_bound(date);
		if (it == _csv.begin()) {
			std::cerr << "Error: no available date.\n";
			return -1;
		}
		--it;
	}
	return (it->second);
}