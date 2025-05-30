/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:11:44 by hetan             #+#    #+#             */
/*   Updated: 2025/05/19 22:27:16 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
double ScalarConverter::_double = 0;
float ScalarConverter::_float = 0;



ScalarConverter::ScalarConverter()
{
	std::cout << "[ScalarConverter Default constructor]" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &source)
{
	std::cout << "[ScalarConverter Copy constructor]" << std::endl;
	*this = source;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source)
{
	std::cout << "[ScalarConverter Copy Assignment]" << std::endl;

	if (this !=  &source)
		*this = source;

	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "[ScalarConverter Destructor]" << std::endl;
}

int	ScalarConverter::isPrintable(string str)
{
	int n = 0;

	while (str[n])
	{
		if (str[n] < ' ' || str[n] > '~')
			return (0);
		n++;
	}
	return (1);
}

void ScalarConverter::toPrint(const string p_char, const string p_int, const string p_flt, const string p_dbl)
{
	std::cout << "char: " << p_char << std::endl;
	std::cout << "int: " << p_int << std::endl;
	std::cout << "float: "<< p_flt << std::endl;
	std::cout << "double: " << p_dbl << std::endl;
}

const char *ScalarConverter::UnprintableCharException::what() const throw()
{
	return ("Error: Not a displayable Character");
}


void ScalarConverter::convert(string str)
{
	if (!isPrintable(str))
		throw(ScalarConverter::UnprintableCharException());

	type t = ScalarConverter::getType(str);

	if (t == POSINF)
	{
		ScalarConverter::toPrint(
			"impossible",
			"impossible",
			"+inff",
			"+inf"
		);
	}
	else if (t == NEGINF)
	{
		ScalarConverter::toPrint(
			"impossible",
			"impossible",
			"-inff",
			"-inf"
		);
	}
	else if (t == CHAR)
	{
		_char = *str.begin();
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else if (t == INT)
	{
		_int = std::atoi(str.c_str());
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
	else if (t == FLOAT)
	{
		_float = std::atof(str.c_str());
		_char = static_cast<char>(_float);
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
	}
	else if (t == DOUBLE)
	{
		_double = std::atof(str.c_str());
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
	}
	if (_char < ' ' || _char > '~')
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: \'" << _char << "\'" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << _float << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << _double << std::endl;

}

type ScalarConverter::getType(string str)
{
	int n = 0;
	unsigned int count_dot= 0;
	unsigned int after_dot = 0;
	unsigned char ischar = 0;

	if (str == "+inf" || str == "+inff")
		return (POSINF);
	else if (str == "-inf" || str == "-inff")
		return(NEGINF);
	else if (str == "nan" || str == "nanf")
		return (NANF);
	
	if (!str.empty() && *str.begin() == '-')
		n++;

	while (str[n] && (n != static_cast<int>(str.length() - 1)))
	{
		if (str[n] == '.')
			count_dot++;
		else if (!(str[n] >= '0' && str[n] <= '9'))
			ischar = 1;
		if (count_dot == 1 && !ischar)
			after_dot++;
		if (count_dot > 1)
			ischar = 1;
		n++;
	}
	if (str.length() <= 2 && !(str[n] >= '0' && str[n] <= '9'))
		ischar = 1;

	if (after_dot && count_dot <= 1 && !ischar && str[str.size() - 1] != 'f')
		return(DOUBLE);
	else if (after_dot && count_dot <= 1 && !ischar && str[str.size() - 1] == 'f')
		return (FLOAT);
	if (ischar)
		return (CHAR);
	else
		return (INT);
}