#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <cstdint>
# include <bitset>

typedef struct sData {
	int	value;
} Data;

std::uintptr_t	serialize( Data * ptr );
Data			*deserialize( std::uintptr_t raw );

#endif