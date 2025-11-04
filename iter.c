t_complex square(t_complex x)
{
	t_complex res;

	res.re = (x.re * x.re) - (x.im * x.im);
	res.im = 2 * x.re * x.im;
	return(res);
}

t_complex	sum(t_complex x, t_complex y)
{
	t_complex sum;
	sum.re = x.re + y.re;
	sum.im = x.im + y.im;
	return (sum);
}

int fractal_iter(t_fractal *f, t_complex z0, t_complex c)
{
	t_complex z;
	double z_sqr;
	int	i;

	i = 0;
	z = z0;
	while (i < f->max_iter)
	{
		z_sqr = (z.re * z.re) + (z.im * z.im);
		if (z_sqr > 4)
			break;
		z = square(z);
		z = sum(z, c);
		i++;
	}
	return (i);
}