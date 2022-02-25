#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char **argv)
{
	double num = 0;

	try
	{
		num	= std::stoi(argv[argc - 1]);
		num = std::stof(argv[argc - 1]);
		num = std::stod(argv[argc - 1]);
	}
	catch( std::exception & e )
	{
		num = argv[1][0];
	}

	std::cout << "char: " << (char)num << std::endl;
	std::cout << "int: " << (int)num << std::endl;
	std::cout << "float: " << std::setprecision(2) << (float)num << "f" << std::endl;
	std::cout << "double: " << (double)num << std::endl;
	return (0);
}