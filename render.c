#include "fractol.h"

static void calc_range(t_fract *f)
{
    f->step_re = (f->max_re - f->min_re) / WIDTH;
    f->step_im = (f->max_im - f->min_im) / HEIGHT;
}

void mapping(t_fract *f)
{
    if (f->type == 1)
    {
        f->min_re = -2.0;
        f->max_re = 1.0;
        f->min_im = -1.5;
        f->max_im = 1.5;
    }
    else
    {
        f->min_re = -2.0;
        f->max_re = 2.0;
        f->min_im = -2.0;
        f->max_im = 2.0;
    }
}

static void find_pos(t_fract *f, int x, int y)
{
    if (f->type == 1)
    {
        f->c_re = f->min_re + x * f->step_re;
        f->c_im = f->max_im - y * f->step_im;
        f->z_re = 0;
        f->z_im = 0;
    }
    else
    {
        f->z_re = f->min_re + x * f->step_re;
        f->z_im = f->max_im - y * f->step_im;
        f->c_re = f->jr;
        f->c_im = f->ji;
    }
}

static void iteration(t_fract *f)
{
    int     i = 0;
    double  tmp;

    while (i < MAX_ITER)
    {
        tmp = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
        f->z_im = 2 * f->z_re * f->z_im + f->c_im;
        f->z_re = tmp;

        if (f->z_re * f->z_re + f->z_im * f->z_im > 4)
        {
            f->iter_count = i;
            return;
        }
        i++;
    }
    f->iter_count = MAX_ITER;
}

static void coloring(t_fract *f, int x, int y)
{
    int color;

    if (f->iter_count == MAX_ITER)
        color = 0x000000; // Siyah
    else
    {
        // Daha smooth renk geçişi
        double t = (double)f->iter_count / MAX_ITER;
        int r = (int)(9 * (1 - t) * t * t * t * 255);
        int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
        color = (r << 16) | (g << 8) | b;
    }

    char *px = f->img.addr + (y * f->img.line_len + x * (f->img.bpp / 8));
    *(unsigned int *)px = color;
}

void render_fractal(t_fract *f)
{
    int i;
    int j;

    mlx_destroy_image(f->mlx, f->img.img);
    f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->img.addr = mlx_get_data_addr(f->img.img,
            &f->img.bpp, &f->img.line_len, &f->img.endian);

    calc_range(f);
    i = 0;
    while (i < WIDTH)
    {
        j = 0;
        while (j < HEIGHT)
        {
            find_pos(f, i, j);
            iteration(f);
            coloring(f, i, j);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
