/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:40:58 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/11 19:59:53 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <vector>
# include <sstream>
# include <stdlib.h>

class RPN
{
	private:

	public:

		RPN();
		RPN(RPN const &copy);
		~RPN();

		RPN& operator=(RPN const & rhs);

};

struct Operation {
    std::string operatorSymbol;
    int (*operationFunction)(int, int);
};

int	opsum(int result, int nb);
int	opsub(int result, int nb);
int	opmul(int result, int nb);
int	opdiv(int result, int nb);

#endif