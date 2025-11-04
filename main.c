#include "fractol.h"

int arg_check(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			return(1);
		else
			return (0);	
	}
	else if (ac == 4)
	{
		if (ft_strcmp (av[1], "julia") == 0)
			return(2);
		else
			return (0);
	}
	return (0);
}

void init_mlx(t_fractal *f)
{
	//mlx_init() grafik sistemiyle bağlantı kurar.
	//mlx_new_window() bu bağlantı üzerinden belirtilen boyut ve isimde bir pencere oluşturur.
    f->mlx = mlx_init();
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");

	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	 f->img_data = mlx_get_data_addr(f->img, &f->bpp, &f->line_len,&f->endian);
}

int main (int ac, char **av)
{
	int	type;
	t_fractal f;

	//argüman olarak fractal tipini al
	type = arg_check(ac, av);
	//geçersiz argüman kontrolü
	if (type == 0)
	{
		print_usage();
		return (1);
	}
	//MLX ve fractal başlatma
	init_mlx(&f);
	//fractal türünü başlat
	init_fractal(&f, type, av, ac);
	//fractal render et
	render(&f);
	mlx_key_hook(f.win, handle_keypress, &f);
	mlx_mouse_hook(f.win, handle_mouse, &f);
	mlx_hook(f.win, 17, 0, handle_close, &f);
	//olay döngüsünü başlat
	mlx_loop(f.mlx);
	return (0);
}
