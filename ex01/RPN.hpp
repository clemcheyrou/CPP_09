/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:40:58 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/09/11 17:42:01 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <stdlib.h>
# include <stdexcept>

struct Operation {
    std::string operatorSymbol;
    int (*operationFunction)(int, int);
};

bool	isOperator(std::string &token);
bool	RPN(std::string &av, std::stack<int> stack);

#endif