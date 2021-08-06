#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int		ft_puts(const char *s) {
	for (; *s; s++)
		write(1, s, 1);
	return 1;
}

const char *err = "Error: Operation file corrupted\n";
struct {
	int		w;
	int		h;
	char	b;
	char	ps[300][302];
}	z;
struct {
	char	t;
	float	x;
	float	y;
	float	r;
	char	c;
}	cr;
FILE *f;

int		main(int ac, char *av[]) {
	if (ac != 2)
		return ft_puts("Error: argument\n");
	f = fopen(av[1], "r");
	if (   !f
		|| fscanf(f, "%d %d %c\n", &z.w, &z.h, &z.b) != 3
		|| z.w < 0 || z.w > 300 || z.h < 0 || z.h > 300)
		return ft_puts(err);
	for (int i = 0; i < z.h; i++) {
		memset(z.ps[i], z.b, z.w);
		z.ps[i][z.w] = '\n';
		z.ps[i][z.w + 1] = '\0';
	}
	int r;
	while ((r = fscanf(f, "%c %f %f %f %c\n", &cr.t, &cr.x, &cr.y, &cr.r, &cr.c))
		== 5)
	{
		//draw();
	}
	if (r != EOF)
	 	return ft_puts(err);
	for (int i = 0; i < z.h; i++)
		ft_puts(z.ps[i]);
}
