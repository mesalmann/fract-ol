#include "fractol.h"

int close_all(t_fract *f)
{
    mlx_destroy_image(f->mlx, f->img.img);
    mlx_destroy_window(f->mlx, f->win);
    exit(0);
    return (0);
}

int close_x(t_fract *f)
{
    return close_all(f);
}

int key_hook(int keycode, t_fract *f)
{
    double shift;
    if (keycode == 65307) // ESC
        close_all(f);
    shift = (f->max_re - f->min_re) * 0.1; // %10 kaydır

    if (keycode == 65361) // Left arrow
    {
        f->min_re -= shift;
        f->max_re -= shift;
        render_fractal(f);
    }
    else if (keycode == 65363) // Right arrow
    {
        f->min_re += shift;
        f->max_re += shift;
        render_fractal(f);
    }
    else if (keycode == 65364) // Up arrow
    {
        f->min_im -= shift;
        f->max_im -= shift;
        render_fractal(f);
    }
    else if (keycode == 65362) // Down arrow
    {
        f->min_im += shift;
        f->max_im += shift;
        render_fractal(f);
    }
    return (0);
}

int mouse_hook(int button, int x, int y, t_fract *f)
{
    (void)x;
    (void)y;

    double scale;

    if (button == 4)         
        scale = 1.1;
    else if (button == 5)   
        scale = 0.9;
    else
        return (0);

    double center_re = (f->min_re + f->max_re) / 2.0;
    double center_im = (f->min_im + f->max_im) / 2.0;

    double new_range_re = (f->max_re - f->min_re) / scale;
    double new_range_im = (f->max_im - f->min_im) / scale;

    f->min_re = center_re - new_range_re / 2.0;
    f->max_re = center_re + new_range_re / 2.0;

    f->min_im = center_im - new_range_im / 2.0;
    f->max_im = center_im + new_range_im / 2.0;

    render_fractal(f);
    return (0);
}

void hooks(t_fract *f)
{
    mlx_hook(f->win, 2, 1L<<0, key_hook, f);
    mlx_hook(f->win, 4, 1L<<2, mouse_hook, f);
    mlx_hook(f->win, 17, 0, close_x, f);
}
 