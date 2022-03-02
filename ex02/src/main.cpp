#include "../inc/utils.hpp"

#define LOOPSIZE 10

int	main( void )
{
	Base	*ptr;

	std::cout << "First we identify pointers" << std::endl;

	for (int i = 0; i < LOOPSIZE; i++)
	{
		ptr = generate();
		identify(ptr);
		delete	ptr;
	}
	std::cout << "\nThen we identify references" << std::endl;

	for (int i = 0; i < LOOPSIZE; i++)
	{
		ptr = generate();
		Base	&ref = *ptr;
		identify(ref);
		delete	ptr;
	}

	return (0);
}
