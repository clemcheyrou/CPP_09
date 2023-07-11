/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:43:54 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/11 20:00:02 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

Operation operations[4] = {
    { "+", &opsum },
    { "-", &opsub },
    { "*", &opmul },
    { "/", &opdiv }
};

bool isnumeric(std::string const &str)
{
    return (!str.empty() && (str.find_first_not_of("0123456789") == std::string::npos || str == "10"));
}

bool isoperator(std::string const &str)
{
    return (!str.empty() && (str.find_first_not_of("-+*/") == std::string::npos));
}

void operate(std::string it, int &result, int calcul)
{
	for (int i = 0; i < 4; i++)
	{
		if (it == operations[i].operatorSymbol)
		{
			result = operations[i].operationFunction(result, calcul);
			break;
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Wrong number of arguments" << std::endl, 0);
	else
	{
		std::istringstream iss(av[1]);
		std::vector<std::string> args;
		
		std::string arg;
		while (iss >> arg)
			args.push_back(arg);
		if (args.empty() == true || !isnumeric(args.front()) || isnumeric(args.back()))
			return (std::cerr << "Error" << std::endl, 0);

		int total;
		bool init_total = false;
		std::vector<std::string> tmp;
		for (std::vector<std::string>::const_iterator it = args.begin(); it != args.end(); ++it)
		{
			if (isnumeric(*it))
				tmp.push_back(*it);
			else if (isoperator(*it))
			{
				int calcul = 0;
				for (std::vector<std::string>::iterator nb = tmp.begin(); nb != tmp.end(); ++nb)
				{
					if (nb == tmp.begin())
						calcul = atoi((*nb).c_str());
					else
						operate(*it, calcul, atoi((*nb).c_str()));
				}
				if (init_total == false)
				{
					total = calcul;
					init_total = true;
				}
				else
					operate(*it, total, calcul);
				tmp.clear();
			}
			else
				return (std::cerr << "Error" << std::endl, 0);
		}
		std::cout << "TOTAL: " << total << std::endl;
		return (total);
	}
}
