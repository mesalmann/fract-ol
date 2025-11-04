#include "fractol.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

double	ft_pow(double flag)
{
	int i;
	i = 1;
	while(flag > 0)
	{
		i = i * 10;
		flag--;
	}
	return (i);
}

void parse_number(char *str, double *res, double *flag, int *i)
{
    while (str[*i])
    {
        if (str[*i] == '.')
        {
            if (*flag != 0)
                break;
            (*flag)++;
            (*i)++;
        }
        else if (str[*i] >= '0' && str[*i] <= '9')
        {
            *res = *res * 10 + (str[*i] - '0');
            if (*flag != 0)
                (*flag)++;
            (*i)++;
        }
        else
            break;
    }
}

double ft_atof(char *str)
{
	double	res;
	double	sign;
	double flag;
	int	i;

	flag = 0;
	i = 0;
	res = 0;
	sign = 1;

	if (str[i] == '-')
	{
			sign = -1;
			i++;
	}
	parse_number(str, &res, &flag, &i);
    if (flag > 0)
    {
        res = res / ft_pow(flag - 1);
    }
	return (res * sign);
}

void print_usage(void)
{
    write(1, "Usage:\n", 7);
    write(1, "  ./fractol mandelbrot\n", 22);
    write(1, "  ./fractol julia <real> <imag>\n", 32);
    write(1, "\nExamples:\n", 11);
    write(1, "  ./fractol mandelbrot\n", 22);
    write(1, "  ./fractol julia -0.7 0.27015\n", 31);
}