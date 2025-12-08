#include "fractol.h"

int ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while(str1[i] && str1[i] == str2[i])
	{
		i++;
	}
	return(str1[i]-str2[i]);
}
static void init_mlx(t_fract *f)
{
    f->mlx = mlx_init();
    if (!f->mlx)
        exit(1);

    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
    if (!f->win)
        exit(1);

    f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->img.addr = mlx_get_data_addr(f->img.img,
            &f->img.bpp, &f->img.line_len, &f->img.endian);
}

int main(int ac, char **av)
{
    t_fract f;

    if (!parse_arg(ac, av, &f))
        return (1);

    init_mlx(&f);
	mapping(&f);
    render_fractal(&f);
    hooks(&f);

    mlx_loop(f.mlx);
    return (0);
}
