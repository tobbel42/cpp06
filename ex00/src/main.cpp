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
		data.err[i] = 0;
	int			type = 0;

	while (typeCheck[type] && !typeCheck[type](argv[1]))
		type++;


	if (type == CHAR)
		data.c = argv[1][0];
	else if (type == INT)
	{
		if (strtol(argv[1], NULL, 10) > (long)std::numeric_limits<int>::max() ||
			strtol(argv[1], NULL, 10) < (long)std::numeric_limits<int>::min() ||
			errno == ERANGE)
			data.err[INT] = ERR_RANGE;
		else
			data.i = strtol(argv[1], NULL, 10);
	}
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
		case INT :{
			if (data.err[INT])
				data.err[FLOAT] = ERR_IMPOSSIBLE;
			else
 				data.f = (float)data.i;
		}
		case FLOAT :{
			if (data.err[FLOAT])
				data.err[DOUBLE] = ERR_IMPOSSIBLE;
			else
	 			data.d = (double)data.f;
		}
	};

	/*
	//Casting to a less precise type -> data is omited, overflows can happen
	*/
	switch(type) {
		case DOUBLE : {
			if ((data.d > (double)std::numeric_limits<float>::max() ||
				data.d < (double)std::numeric_limits<float>::lowest()) &&
				data.d != std::numeric_limits<double>::infinity() &&
				data.d != -1 * std::numeric_limits<double>::infinity())
				data.err[FLOAT] = ERR_RANGE;
			data.f = (float)data.d;
		}
		case FLOAT : {
			if (data.err[FLOAT])
				data.err[INT] = ERR_IMPOSSIBLE;
			else if (data.f == std::numeric_limits<float>::infinity() ||
				std::isnan(data.f) ||
				data.f == -1 * std::numeric_limits<float>::infinity())
				data.err[INT] = ERR_IMPOSSIBLE;
			else if (data.f > (float)std::numeric_limits<int>::max() ||
				data.f < (float)std::numeric_limits<int>::min())
				data.err[INT] = ERR_RANGE;
			data.i = (int)data.f;
		}
		case INT : {
			if (data.err[INT])
				data.err[CHAR] = ERR_IMPOSSIBLE;
			else if (data.i > std::numeric_limits<char>::max() ||
				data.i < std::numeric_limits<char>::min())
				data.err[CHAR] = ERR_RANGE;
			else
			{
				data.c = (char)data.i;
				if (!isPrint(data.c))
					data.err[CHAR] = ERR_NOPRINT;
			}
		}
	};

	int	len = ft_strlen(argv[1]);

	printChar(data);
	printInt(data);
	printFloat(data, len, type);
	printDouble(data, len, type);

	return (0);
}
