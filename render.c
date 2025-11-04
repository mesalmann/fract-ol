#include "fractol.h"
void put_pixel(t_fractal *f, int x, int y, int color)
{
    char *pixel;
    
    pixel = f->img_data + (y * f->line_len + x * (f->bpp / 8));

    *(unsigned int *)pixel = color;
}

int get_color(t_fractal *f, int iter)
{
    if (iter == f->max_iter)
        return (0x000000);
    
    return (0x00FCBE11 * iter);
}

t_complex pixel_to_complex(int x, int y, t_fractal *f)
{
    t_complex result;
    double scale_x;
    double scale_y;

    scale_x = (f->max_real - f->min_real) / f->zoom;
    scale_y = (f->max_imag - f->min_imag) / f->zoom;
    
    result.re = f->min_real + ((double)x / WIDTH) * scale_x + f->offset_x;
    result.im = f->max_imag - ((double)y / HEIGHT) * scale_y + f->offset_y;
    
    return (result);
}

static void	render_mandelbrot(t_fractal *f)
{
	int			x;
	int			y;
	int			iter;
	int			color;
	t_complex	c;
	t_complex	z0;

	y = 0;
	z0.re = 0;
	z0.im = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = pixel_to_complex(x, y, f);
			iter = fractal_iter(f, z0, c);
			color = get_color(f, iter);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

static void	render_julia(t_fractal *f)
{
	int			x;
	int			y;
	int			iter;
	int			color;
	t_complex	z0;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z0 = pixel_to_complex(x, y, f);
			iter = fractal_iter(f, z0, f->c);
			color = get_color(f, iter);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	render(t_fractal *f)
{
	if (f->type == MANDELBROT)
		render_mandelbrot(f);
	else if (f->type == JULIA)
		render_julia(f);
}