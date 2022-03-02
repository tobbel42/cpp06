#include "../inc/utils.hpp"

Base	*generate( void )
{
	std::ifstream	rando;
	char			buf;

	rando.open("/dev/random", std::ios::out);
	if (!rando.good())
	{
		std::cout << "Error" << std::endl;
		return (NULL);
	}
	
	rando.read(&buf, 1);
	if (buf % 3 == 0)
		return (new A);
	else if (buf % 3 == 1)
		return (new B);
	else
		return (new C);
}

/*
//identify pointer of a polymorphic class
//using dynamicCast -> returns NULL in case of error
*/
void	identify( Base* p )
{
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "A Class" << std::endl;
	if (b)
		std::cout << "B Class" << std::endl;
	if (c)
		std::cout << "C Class" << std::endl;
}

/*
//identifying references with try catch Block
//referenc can never be Null, so Cpp is throwing an Exception
//on incorrect Cast
*/
void	identify( Base & p )
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		std::cout << "A Class" << std::endl;
		(void)a;
	}
	catch( const std::exception& e ){}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		std::cout << "B Class" << std::endl;
		(void)b;
	}
	catch( const std::exception& e ){}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		std::cout << "C Class" << std::endl;
		(void)c;
	}
	catch( const std::exception& e ){}
}
