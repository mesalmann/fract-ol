#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800

# define MANDELBROT 1
# define JULIA 2

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define MAX_ITER 100

typedef struct s_complex
{
    double  re;
    double  im;
}   t_complex;
typedef struct s_fractal
{
    void        *mlx;
    void        *win;
    void        *img;
    char        *img_data;
    int         bpp;
    int         line_len;
    int         endian;
    
    int         type;
    double      min_real;
    double      max_real;
    double      min_imag;
    double      max_imag;
    
    double      julia_real;
    double      julia_imag;
    t_complex   c;
    
    double      zoom;      
    double      offset_x;  
    double      offset_y;    
    int         max_iter;   
    
}   t_fractal;

int     arg_check(int ac, char **av);
int     ft_strcmp(char *s1, char *s2);
int     fractal_iter(t_fractal *f, t_complex z0, t_complex c);
int     get_color(t_fractal *f, int iter);
int     handle_keypress(int key, t_fractal *f);
int     handle_mouse(int button, int x, int y, t_fractal *f);
int     handle_close(t_fractal *f);
void    put_pixel(t_fractal *f, int x, int y, int color);
void    init_mlx(t_fractal *f);
void    init_fractal(t_fractal *f, int type, char **av, int ac);
void    render(t_fractal *f);
void    print_usage(void);
double  ft_atof(char *str);
t_complex   square(t_complex x);
t_complex   sum(t_complex x, t_complex y);
t_complex   pixel_to_complex(int x, int y, t_fractal *f);
#endif