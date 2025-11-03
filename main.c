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
	//grafik sistemini başlat
    f->mlx = mlx_init();
	//yeni pencere oluştur
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
}

void init_fractal(t_fractal *f, int type, char **av)
{
	//fractalın türünü ayarla
	f->type = type;
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 100;
	
	
	if (type == MANDELBROT)
	{
		//Mandelbrot set sınırlarını ayarla
		f->min_real = -2.0;
		f->max_real = 1.0;
		f->min_imag = -1.5;
		f->max_imag = 1.5;
	}
	else if (type == JULIA)
	{
		//Julia set sınırlarını ayarla
		f->min_real = -1.5;
		f->max_real = 1.5;
		f->min_imag = -1.5;
		f->max_imag = 1.5;
		
		if (av[2] && av[3])
		{
			f->julia_real = ft_atof(av[2]);
			f->julia_imag = ft_atof(av[3]);
		}
		else
		{
			f->julia_real = -0.7;
			f->julia_imag = 0.27015;
		}
		
	}
}

double	ft_pow(double flag)
{
	int i;
	i = 1;
	while(flag > 0)
	{
		i = i * 10;
		flag--;
	}
	return (i);
}

static void	parse_number(char *str, double *res, double *flag, int *i)
{
	while(str[*i])
	{
		if (str[*i] == '.')
		{
			(*i)++;
			(*flag)++;
		}
		if (!str[*i])
        	break;
		if (str[*i] < '0' || str[*i] > '9')
			break;
		if (str*[i])
		{
			*res = *res * 10 + (str[*i] - '0');
			if (*flag != 0)
				(*flag)++;
		}
		(*i)++;
	}
}

double ft_atof(char *str)
{
	double	res;
	double	sign;
	double flag;
	int	i;

	flag = 0;
	i = 0;
	res = 0;
	sign = 1;

	if (str[i] == '-')
	{
			sign = -1;
			i++;
	}
	parse_number(str, &res, &flag, &i);
	res = res / ft_pow(flag - 1);
	return (res * sign);
}

int fractal_iter(t_fractal *f, t_complex z0, t_complex c)
{

}


t_complex   pixel_to_complex(int x, int y, t_fractal *f)
{
	t_complex s;
	double x_ratio;
	double y_ratio;
	double re;
	double im;

	x_ratio = (double)x / WIDTH - 1;
	y_ratio = (double)y / HEIGHT - 1;

	    // Gerçek eksen (x) için oranı complex düzleme çevir:
    // Soldaki en küçük değer (min_real) → sağdaki en büyük (max_real)
	s.re = f->min_real + (x_ratio * (f->max_real - f->min_real));


	// İmajiner eksen (y) için oranı complex düzleme çevir:
    // Ekranda y büyüdükçe aşağı iniyoruz ama complex düzlemde
    // yukarı çıkmak pozitif imajiner demek → bu yüzden ters çeviriyoruz.
    // Yani: üstteki piksel (y=0) → max_imag, alttaki (y=HEIGHT-1) → min_imag
	s.im = f->min_imag - (y_ratio * (f->max_imag - f->min_imag));
	return (s);
}


void	render(t_fractal *f)
{
	int	x;
	int y;
	int iter;
	int color;
	t_complex c;
	t_complex z0;
	
	z0 = {0, 0};
	x = WIDTH;
	y = HEIGHT;
	
	while(y > 0)
	{
		while (x > 0)
		{
			if (f->type == MANDELBROT)
			{
    			c = pixel_to_complex(x, y, f);   // her piksel için farklı
    			z0 = (0, 0);                     // sabit
			}
			else if (f->type == JULIA)
			{
    			z0 = pixel_to_complex(x, y, f);  // her piksel farklı
    			c = f->c;                        // sabit
			}
			iter = fractal_iter(f, z0, c);
			//sayının aralığına göre renk belirle
			color = get_color(&f, iter);
			//x, y pikselini boya
			put_pixel(&f, x, y, color);
			x++;
		}
		y++; 
	}
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
	init_fractal(&f, type, av);
	//fractal render et
	render(&f);
	//olay döngüsünü başlat
	mlx_loop(f.mlx);

	return (0);
}
