/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:11:48 by hetan             #+#    #+#             */
/*   Updated: 2025/05/18 22:11:49 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <exception>
# include <vector>
# include <string>


enum type{
	CHAR, INT, DOUBLE, FLOAT, POSINF, NEGINF, NANF
};

using std::string;

class ScalarConverter
{
	private:
		ScalarConverter();
		static char _char;
		static int _int;
		static double _double;
		static float _float;

	public:
		ScalarConverter(const ScalarConverter &source);
		ScalarConverter &operator=(const ScalarConverter &source);
		~ScalarConverter();

		static void convert(string str);
		static type getType(string str);
		static void toPrint(const string p_char, const string p_int, const string p_flt, const string p_dbl);
		static int	isPrintable(const std::string str);
	
	class UnprintableCharException: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
		
};


#endif