#include "../inc/utils.hpp"

void	printChar( const Data & data )
{
	std::cout << "char: ";
	if (data.err[CHAR] == ERR_IMPOSSIBLE)
		std::cout << "impossible";
	else if (data.err[CHAR] == ERR_NOPRINT)
		std::cout << "Non displayable";
	else if (data.err[CHAR] == ERR_RANGE)
		std::cout << "out of range";
	else
		std::cout << "'" << data.c << "'";
	std::cout << std::endl;
}

void	printInt( const Data & data )
{
	std::cout << "int: ";
	if (data.err[INT] == ERR_IMPOSSIBLE)
		std::cout << "impossible";
	else if (data.err[INT] == ERR_RANGE)
		std::cout << "out of range";
	else
		std::cout << data.i;
	std::cout << std::endl;
}

void	printFloat( const Data & data ,int len, int type )
{
	std::cout << std::showpoint;
	if (type == CHAR)
		std::cout.precision((data.c > 99)? 4 : 3);
	if (type == INT)
		std::cout.precision(len + 1);
	if (type == FLOAT)
		std::cout.precision(len - 2);
	if (type == DOUBLE)
		std::cout.precision(len - 1);
	std::cout << "float: ";
	if (data.err[FLOAT] == ERR_RANGE)
		std::cout << "out of range" << std::endl;
	else if (data.err[FLOAT] == ERR_IMPOSSIBLE)
		std::cout << "impossible" << std::endl;	
	else
	{
		if (data.f == std::numeric_limits<float>::infinity())
			std::cout << "+";
		std::cout << data.f << "f" << std::endl;
	}
}

void	printDouble( const Data & data, int len, int type )
{
	std::cout << std::showpoint;
	if (type == CHAR)
		std::cout.precision((data.c > 99)? 4 : 3);
	if (type == INT)
		std::cout.precision(len + 1);
	if (type == FLOAT)
		std::cout.precision(len - 2);
	if (type == DOUBLE)
		std::cout.precision(len - 1);
	std::cout << "double: ";
	if (data.err[DOUBLE] == ERR_IMPOSSIBLE)
		std::cout << "impossible" << std::endl;	
	else 
	{
		if (data.d == std::numeric_limits<double>::infinity())
			std::cout << "+";
		std::cout << data.d << std::endl;
	}
}