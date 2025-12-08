#include "fractol.h"

static void ft_lower(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        i++;
    }
}

static int parse_julia(t_fract *f, char **av)
{
    f->jr = ft_atod(av[2]);
    f->ji = ft_atod(av[3]);
    return (1);
}

int parse_arg(int ac, char **av, t_fract *f)
{
    if (ac < 2)
    {
        printf("Usage: ./fractol mandelbrot | julia <r> <i>\n");
        return (0);
    }

    ft_lower(av[1]);

    if (!ft_strcmp(av[1], "mandelbrot"))
    {
        if (ac != 2)
        {
            printf("Mandelbrot doesn't take an extra argument.\n");
            return (0);
        }
        f->type = 1;
    }
    else if (!ft_strcmp(av[1], "julia"))
    {
        if (ac != 4)
        {
            printf("Julia usage: ./fractol julia <real> <imag>\n");
            return (0);
        }
        f->type = 2;
        parse_julia(f, av);
    }
    else
    {
        printf("Inavlid fractal name.\n");
        return (0);
    }

    return (1);
}
