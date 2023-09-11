/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:48:05 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/09/11 14:01:39 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <cstdlib>
# include <map>
# include <limits.h>

# define ERROR_DOUBLE "Error: not a number."
# define ERROR_NEG "Error: not a positive number."
# define ERROR_OVERFLOW "Error: too large a number."
# define ERROR_BADINPUT "Error: bad input."

# define CLEAR "\e[0m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[33m"
# define MAGENTA "\e[35m"

class BitcoinExchange
{
	private:
		std::map<std::string, double> _csv;
		BitcoinExchange();
	
	public:

		BitcoinExchange(std::string file);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange(void);

		BitcoinExchange& operator=(BitcoinExchange const & rhs);
		
		double	getBitcoinPrice(std::string const & date) const;

};

#endif