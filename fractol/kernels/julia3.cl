#pragma OPENCL EXTENSION cl_khr_fp64 : enable

#define F_WIDTH		1920
#define F_HEIGHT	1080
#define ITE			60

kernel void julia3(__global double *input,
				   __global int	  *results)
{
	int			id;

	int			x;
	int			y;

	int			i;

	double		re;
	double		im;
	double		ore;
	double		oim;

	double		zoom;
	double		h;
	double		v;
	int			max_ite;
	double		cr;
	double		ci;

	int			random;
	
	id = get_global_id(0);
	x = id % F_WIDTH;
	y = id / F_WIDTH;

	zoom = input[0];
	h = input[1];
	v = input[2];
	max_ite = input[3];
	cr = input[4];
	ci = input[5];
	random = input[6];

	re = 1.5 * (x - F_WIDTH / 2) / (double)(0.500 * (double)F_WIDTH * zoom) + h;
	im = (y - F_HEIGHT / 2) / (double)(0.500 * (double)F_HEIGHT * zoom) + v;

	i = 0;
	while (i < max_ite)
	{
		ore = re;
		oim = im;

		(ore < 0) ? ore = -ore : 0;
		(oim < 0) ? oim = -oim : 0;

		re = ore * ore * ore - oim * oim * oim + cr;
		im = 2 * ore * oim + ci;
		if ((re * re + im * im) > 4)
			break ;
		if ((i + 30 < max_ite))
			i += 30;
		else
			i++;
	}

	if (i == 0)
		results[(y * F_WIDTH) + x] = 0;
	else if (random)
		results[(y * F_WIDTH) + x] = (random * (max_ite - i) << 16) + ((random * 2) * (max_ite - i) << 8) + (random * 3) * (max_ite - i);
	else
		results[(y * F_WIDTH) + x] = ((max_ite - i) << 16) + ((max_ite - i) << 8) + (max_ite - i);
}
