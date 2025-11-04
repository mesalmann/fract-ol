#include "fractol.h"

static void	init_julia(t_fractal *f, int ac, char **av)
{
	f->min_real = -1.5;
	f->max_real = 1.5;
	f->min_imag = -1.5;
	f->max_imag = 1.5;
	if (ac == 4 && av[2] && av[3])
	{
		f->julia_real = ft_atof(av[2]);
		f->julia_imag = ft_atof(av[3]);
	}
	else
	{
		f->julia_real = -0.7;
		f->julia_imag = 0.27015;
	}
	f->c.re = f->julia_real;
	f->c.im = f->julia_imag;
}

static void	init_mandelbrot(t_fractal *f)
{
	f->min_real = -2.0;
	f->max_real = 1.0;
	f->min_imag = -1.5;
	f->max_imag = 1.5;
}

void	init_fractal(t_fractal *f, int type, char **av, int ac)
{
	f->type = type;
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 100;
	if (type == MANDELBROT)
		init_mandelbrot(f);
	else if (type == JULIA)
		init_julia(f, ac, av);
}
