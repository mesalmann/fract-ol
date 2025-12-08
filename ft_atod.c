#include "fractol.h"

double ft_pow(int base, int exp)
{
	double mult;

	mult = 1;
	while (exp > 0)
	{
		mult *= base;
		exp--;
	}
	return (mult);
}

int parse_sign(char *str, int *i)
{
	if (str[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	if (str[*i] == '+')
		(*i)++;
	return (1);
}

double parse_reel(char *str, int *i)
{
	double sum = 0;

	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		sum *= 10;
		sum += (str[*i] - '0');
		(*i)++;
	}
	return (sum);
}

double parse_fraction(char *str, int *i)
{
	double sum = 0;
	int j = 0;

	if (str[*i] == '.')
		(*i)++;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		sum *= 10;
		sum += (str[*i] - '0');
		(*i)++;
		j++;
	}
	return (sum / ft_pow(10, j));
}

static void skip_spaces(char *str, int *i)
{
    while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
        (*i)++;
}

double ft_atod(char *str)
{
	int i = 0;
	int sign;
	double sumr;
	double sumf;

    skip_spaces(str, &i);

	sign = parse_sign(str, &i);
	sumr = parse_reel(str, &i);
	sumf = parse_fraction(str, &i);
	return (sign * (sumr + sumf));
}