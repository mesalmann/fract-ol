#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

// Pencere boyutu
# define WIDTH 800
# define HEIGHT 800

// Fractal tipleri
# define MANDELBROT 1
# define JULIA 2

// Tuş kodları (Linux)
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364

// Mouse
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

// Max iterasyon
# define MAX_ITER 100

// Struct
typedef struct s_fractal
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    int     type;
    double  min_real;
    double  max_real;
    double  min_imag;
    double  max_imag;
    double  julia_real;
    double  julia_imag;
}   t_fractal;

typedef struct s_complex
{
    double  re;
    double  im;
}   t_complex;


int     arg_check(int ac, char **av);
void    print_usage(void);
int     ft_strcmp(char *s1, char *s2);
double  ft_atof(char *str);

void    init_mlx(t_fractal *f);
void    init_fractal(t_fractal *f, int type);
void    render(t_fractal *f);
t_complex   pixel_to_complex(int x, int y, t_fractal *f);
int         fractal_iter(t_fractal *f, t_complex z0, t_complex c);
int         get_color(t_fractal *f, int iter);
void        put_pixel(t_fractal *f, int x, int y, int color);

#endif