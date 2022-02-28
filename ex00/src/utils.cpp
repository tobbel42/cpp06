#include "../inc/utils.hpp"

int	isPrint( char c )
{
	if (c > 32 && c < 127)
		return (1);
	return (0);
}

int isDigit( char c )
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen( char *s )
{
	int i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	isChar( char *str )
{
	int	i = ft_strlen(str);
	if (i != 1 || isDigit(str[0]) || !isPrint(str[0]))
		return (0);
	return (1);
}

int isInt( char *str )
{
	if ((*str == '+' || *str == '-' ) && *(str + 1) )
		str++;
	while (*str)
	{
		if (!isDigit(*str++))
			return (0);
	}
	return (1);
}

int	ft_strncmp(char *s1, const std::string & s2, int n)
{
	int	i = 0;
	while(i < n - 1 && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1[i] - s2[i]);
}

int isFloat( char *str )
{
	bool	left = false;
	bool	right = false;

	if (!ft_strncmp(str, "+inff", 6) || !ft_strncmp(str, "-inff", 6) || !ft_strncmp(str, "nanf", 5))
		return (1);
	if ((*str == '+' || *str == '-' ) && *(str + 1) )
		str++;
	while (*str && *str != '.')
	{
		if (isDigit(*str++))
			left = true;
		else
			return (0);
	}
	if (*str++ != '.')
		return (0);
	while (*str && *str != 'f')
	{
		if (isDigit(*str++))
			left = true;
		else
			return (0);
	}
	return (*str == 'f' && (left || right));
}

int isDouble( char *str )
{
	bool	left = false;
	bool	right = false;

	if (!ft_strncmp(str, "+inf", 5) || !ft_strncmp(str, "-inf", 5) || !ft_strncmp(str, "nan", 4))
		return (1);
	if ((*str == '+' || *str == '-' ) && *(str + 1))
		str++;
	while (*str && *str != '.')
	{
		if (isDigit(*str++))
			left = true;
		else
			return (0);
	}
	if (*str++ != '.')
		return (0);
	while (*str)
	{
		if (isDigit(*str++))
			left = true;
		else
			return (0);
	}
	return ((left || right));
}
