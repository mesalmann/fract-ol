#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>


# define WIDTH 800
# define HEIGHT 700
# define MAX_ITER 100

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

typedef struct s_fract
{
    void    *mlx;
    void    *win;
    t_img   img;

    int     type;

    double  jr;
    double  ji;

    double  min_re;
    double  max_re;
    double  min_im;
    double  max_im;

    double  step_re;
    double  step_im;

    double  c_re;
    double  c_im;

    double  z_re;
    double  z_im;

    int     iter_count;
}   t_fract;

// PROTOTYPES
int     parse_arg(int ac, char **av, t_fract *f);
int     mouse_hook(int button, int x, int y, t_fract *f);
int     key_hook(int keycode, t_fract *f);
int     close_all(t_fract *f);
void    hooks(t_fract *f);
void    render_fractal(t_fract *f);
double  ft_atod(char *str);
int     ft_strcmp(char *str1, char *str2);
void mapping(t_fract *f);
#endif
