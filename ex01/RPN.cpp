/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:41:28 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/09/11 17:47:53 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "RPN.hpp"

bool	isOperator(std::string &token)
{
	return (!token.empty() && (token.find_first_not_of("-+*/") == std::string::npos));
}

int	opsum(int nb1, int nb2)
{
	return (nb1 + nb2);
}

int	opsub(int nb1, int nb2)
{
	return (nb1 - nb2);	
}

int	opmul(int nb1, int nb2)
{
	return (nb1 * nb2);	
}

int	opdiv(int nb1, int nb2)
{
	if (nb2 == 0)
		throw std::runtime_error("Error");
	return (nb1 / nb2);	
}

Operation operations[4] = {
    { "+", &opsum },
    { "-", &opsub },
    { "*", &opmul },
    { "/", &opdiv }
};


bool	operation(std::string token, std::stack<int> &stack)
{
	if (stack.size() <= 1)
		return (std::cerr << "Error" << std::endl, true);
		
	int	nb2 = stack.top();
	stack.pop();
	int	nb1 = stack.top();
	stack.pop();

	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		if (token == operations[i].operatorSymbol)
		{
			result = operations[i].operationFunction(nb1, nb2);
			stack.push(result);
			break;
		}
	}
	return (false);
}

bool isnumeric(std::string const &str)
{
    return (!str.empty() && (str.find_first_not_of("0123456789") == std::string::npos));
}

bool	RPN(std::string &arg, std::stack<int> stack)
{
	std::istringstream	iss(arg);
	std::string			token;

	while (iss >> token)
	{
		if (!isnumeric(token) && !isOperator(token))
			return (std::cerr << "Error" << std::endl, true);
		else if (std::isdigit(token[0]))
			stack.push(token[0] - '0');
		else if (isOperator(token))
			if (operation(token, stack))
				return (1);
	}
	std::cout << stack.top() << std::endl;
	return (0);
}