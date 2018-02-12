__kernel void				iter_axone(__global int *img, int it_max, int x,
int y, float zoom, float decX, float decY, int psy, float mx, float my)
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
	float					sizeRL;
	float					sizeIM;
	int						i;
	int						j;

	i = get_global_id(0);
	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoomX = x / (x2 - x1) * zoom;
	zoomY = y / (y2 - y1) * zoom;
	curX = i % x;
	curY = i / x;
	cRL = 0;
	cIM = 1;
	if (mx > 0 && my > 0)
	{
		zRL = (curX - (x * mx)) / zoomX + decX;
		zIM = (curY - (y * my)) / zoomY + decY;
		}
	else
	{
		zRL = (curX - (x / 2)) / zoomX + decX;
		zIM = (curY - (y / 2)) / zoomY + decY;
	}
	j = 0;
	sizeRL = x1 * -1 + x2;
	sizeIM = y1 * -1 + y2;
	while (zRL * zRL + zIM * zIM < 4 && j < it_max)
	{
		tmp = zRL;
		zRL = zRL * zRL - zIM * zIM + cRL;
		zIM = 2 * zIM * tmp + cIM;
		j++;
	}
	if (j != it_max)
	{
		img[i] = j * 255 * psy / it_max;
	}
	else
	{
		img[i] = 99999999;
	}
}
