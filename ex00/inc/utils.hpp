#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cerrno>
# include <cmath>
# include <limits>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

typedef int	(*typeChecks)(char *);
typedef struct	Data{
	char	c;
	int		i;
	float	f;
	double	d;
	int		err[4];
} Data;

# define ERR_NOPRINT 1
# define ERR_IMPOSSIBLE 2
# define ERR_RANGE 3

int	isPrint( char c );
int isDigit( char c );
int	ft_strlen( char *s );
int	isChar( char *str );
int isInt( char *str );
int	ft_strncmp(char *s1, const std::string & s2, int n);
int isFloat( char *str );
int isDouble( char *str );

void	printChar( const Data & data );
void	printInt( const Data & data );
void	printFloat( const Data & data ,int len, int type );
void	printDouble( const Data & data, int len, int type );

#endif