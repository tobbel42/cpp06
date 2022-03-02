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
	}
	std::cout << "\nThen we identify references" << std::endl;

	for (int i = 0; i < LOOPSIZE; i++)
	{
		Base	&ref = *generate();
		identify(ref);
	}

	return (0);
}
