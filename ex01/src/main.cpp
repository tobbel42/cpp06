#include "../inc/utils.hpp"

int	main( void )
{
	Data			d[2];
	Data			*f;
	std::uintptr_t	s;

	d[0].value = 10;
	d[1].value = 2;

	s = serialize(d);

	std::cout << "Adress of Data struct\n" << &d << std::endl;
	std::cout << "Serialized pointer\n" << s << std::endl;
	std::cout << "Transform into Hexbase\n" << std::hex << "0x" << s << std::dec << std::endl;
	
	std::cout << "\nNow stepping byte by byte, till we reach d[1]" << std::endl;
	for (size_t i = 0; i <= sizeof(Data); i++)
	{
		f = deserialize(s);
		std::cout << "Pointer" << std::endl;
		std::cout << std::hex << "0x" << s << std::dec << std::endl;
		std::cout << "Value" << std::endl;
		std::cout << f->value << std::endl;
		std::cout << "BitValue" << "\n" << std::bitset<32>(f->value) << "\n" << std::endl;
		s++;
	}
	std::cout << "traditional Pointer to d[1]\n" << &d[1] << std::endl;
	std::cout << "Deserialized seriaized Pointer to d[1]\n" << f << std::endl;
	return (0);
}
