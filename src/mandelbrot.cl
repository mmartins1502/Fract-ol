__kernel void				iter_mandelbrot(__global int *img, int it_max, int x, int y, float zoom, float decX, float decY, int psy, float mx, float my)
{
	float					x1;
	float					x2;
	float					y1;
	float					y2;
	float					zoomX;
	float					zoomY;
	int						curX;
	int						curY;
	float					cRL;
	float					cIM;
	float					zRL;
	float					zIM;
	float					tmp;
	int						i;
	int						j;

	i = get_global_id(0);
	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoomX = (x / (x2 - x1)) * zoom;
	zoomY = (y / (y2 - y1)) * zoom;
	curX = i % x;
	curY = i / x;
	if (mx > 0 && my > 0)
	{
		cRL = ((curX) - (x * mx)) / zoomX + (x1 / 4 + decX);
		cIM = ((curY) - (y * my)) / zoomY + decY;
	}
	else
	{
		cRL = ((curX) - (x / 2)) / zoomX + (x1 / 4 + decX);
		cIM = ((curY) - (y / 2)) / zoomY + decY;
	}
	zRL = 0;
	zIM = 0;
	j = 0;
	while (zRL * zRL + zIM * zIM < 4 && j < it_max)
	{
		tmp = zRL;
		zRL = zRL * zRL - zIM * zIM + cRL;
		zIM = (2 * zIM * tmp) + cIM;
		j++;
	}
	if (j != it_max)
	{
		img[i] = j * 255 * psy / it_max;
	}
	else
	{
		img[i] = 0;
	}
}
