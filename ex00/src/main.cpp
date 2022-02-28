#include "../inc/utils.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		return (1);
	}

	typeChecks	typeCheck[] = { isChar, isInt, isFloat, isDouble, NULL };
	Data		data;
	for (int i = 0; i < 4; i++)
		data.e[i] = 0;
	int			type = 0;

	while (typeCheck[type] && !typeCheck[type](argv[1]))
		type++;

	//ToDO E Catcher
	if (type == CHAR)
		data.c = argv[1][0];
	else if (type == INT)
		data.i = strtol(argv[1], NULL, 10);
	else if (type == FLOAT)
		data.f = strtof(argv[1], NULL);
	else if (type == DOUBLE)
		data.d = strtod(argv[1], NULL);
	else
	{
		std::cout << "Unknown literal" << std::endl;
		return (1);
	}

	/*
	//Casting to a more precise type -> no problem, data can be represented
	*/
	switch(type) {
		case CHAR : data.i = (int)data.c;
		case INT : data.f = (float)data.i;
		case FLOAT : data.d = (double)data.f;
	};

	/*
	//Casting to a less precise type -> data is omited, overflows can happen
	*/
	switch(type) {
		case DOUBLE : data.f = (float)data.d;
		case FLOAT : data.i = (int)data.f;
		case INT : {
			if (data.i > std::numeric_limits<char>::max())
				data.e[CHAR] = ERR_OVERFLOW;
			else if (data.i > std::numeric_limits<char>::min())
				data.e[CHAR] = ERR_UNDERFLOW;
			else if (data.e[INT])
				data.e[CHAR] = data.e[INT];
			data.c = (char)data.i;
			if (!isPrint(data.c))
				data.e[CHAR] = ERR_NOPRINT;
		}
	}; //ToDo caster functions, printer functions



	std::cout << "char: "	<< data.c << std::endl;
	std::cout << "int: "	<< data.i << std::endl;
	std::cout << std::showpoint;
	int	len = ft_strlen(argv[1]);
	if (type == CHAR)
		std::cout.precision((data.c > 99)? 4 : 3); // toDo
	if (type == INT)
		std::cout.precision(len + 1);
	if (type == FLOAT)
		std::cout.precision(len - 2);
	if (type == DOUBLE)
		std::cout.precision(len - 1);
	std::cout << "float: "	<< data.f << "f" << std::endl;
	std::cout << "double: "	<< data.d << std::endl;

	return (0);
}