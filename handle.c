#include "fractol.h"
int handle_keypress(int key, t_fractal *f)
{
    if (key == KEY_ESC)
    {
        mlx_destroy_window(f->mlx, f->win);
        exit(0);
    }
    if (key == KEY_LEFT)
        f->offset_x = f->offset_x - (0.5 / f->zoom);
    if (key == KEY_RIGHT)
        f->offset_x = f->offset_x + (0.5 / f->zoom);
    if (key == KEY_UP)
        f->offset_y = f->offset_y - (0.5 / f->zoom);
    if (key == KEY_DOWN)
        f->offset_y = f->offset_y + (0.5 / f->zoom);
    render(f);
    return (0);
}

int handle_mouse(int button, int x, int y, t_fractal *f)
{
    (void)x;
    (void)y;
    
    if (button == MOUSE_SCROLL_UP)
        f->zoom = f->zoom * 1.2;
    if (button == MOUSE_SCROLL_DOWN)
        f->zoom = f->zoom / 1.2;
    render(f);
    return (0);
}

int handle_close(t_fractal *f)
{
    mlx_destroy_window(f->mlx, f->win);
    exit(0);
}