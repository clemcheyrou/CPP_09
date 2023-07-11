/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:45:56 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/11 16:29:27 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	isvalid_date(std::string date)
{
	std::istringstream iss(date);
	int year, month, day;
	
	if (iss >> year && iss.get() == '-' && iss >> month && iss.get() == '-' && iss >> day && iss.eof())
	{
		bool is_leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (month >= 1 && month <= 12)
		{
			if (month == 2)
			{
				if (day >= 1 && day <= (is_leapyear ? 29 : 28))
						return (1);
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day >= 1 && day <= 30)
					return (1);
			}
			else
			{
				if (day >= 1 && day <= 31)
					return (1);
			}
		}
	}
	return (0);
}

int	isvalid_num(double num)
{
	if (num < 0)
		return (std::cerr << "Error: not a positive number." << std::endl, 0);
	else if (num >= 2147483648)
		return (std::cerr << "Error: too large a number." << std::endl, 0);
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Error: could not open file." << std::endl, 1);
	else
	{
		std::ifstream ifs(av[1]);
		if (!ifs)
			return (std::cout << "Error: could not open file." << std::endl, 1);

		BitcoinExchange btc("data.csv");
		std::string	str;
		while (std::getline(ifs, str))
		{
			std::istringstream iss(str);
			std::string date;
			double num;
			if (str == "date | value")
				continue;
			else if (std::getline(iss, date, '|') && iss >> num)
			{
				date.erase(10, 1);
				if (isvalid_date(date) && date.size() == 10)
				{
					if (isvalid_num(num) && btc.getBitcoinPrice(date) != -1)
						std::cout << date << " => " << num << " = " << (num * btc.getBitcoinPrice(date)) << std::endl;
						
				}
				else
					std::cerr << "Error: bad input => " << str << std::endl;
			}
			else
				std::cerr << "Error: bad input => " << str << std::endl;
		}
		
		return (0);
	}
}