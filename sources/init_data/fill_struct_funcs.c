#include "x_mini_struct.h"
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void	update_cam(t_cam *cam);

void	print_tab(double tab[], char *str);

void	fill_struct_A(t_data *data, double tab[])
{
	int i;

	i = 0;
	// printf("A:\n");
	// while (tab[i] != 1024)
	// {
	// 	if (i == 0)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 1)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 2)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 3)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	i++;
	// }
}

void	fill_struct_C(t_data *data, double tab[])
{
	data->cam.origin_vect.axis[0] = tab[0];
	data->cam.origin_vect.axis[1] = tab[1];
	data->cam.origin_vect.axis[2] = tab[2];
	data->cam.forward_vect.axis[0] = tab[3];
	data->cam.forward_vect.axis[1] = tab[4];
	data->cam.forward_vect.axis[2] = tab[5];
	data->cam.fov = tab[6];
}

int	create_and_fill_struct_sp(t_data *data, char *map_path, double tab[])
{
	static	int i = 0;

	data->spheres[i].origin_vect.axis[0] = tab[0];
	data->spheres[i].origin_vect.axis[1] = tab[1];
	data->spheres[i].origin_vect.axis[2] = tab[2];
	data->spheres[i].diameter = tab[3];
	data->spheres[i].square_radius = tab[3] / 2 * tab[3] / 2;
	data->spheres[i].color.rgb[0] = tab[4];
	data->spheres[i].color.rgb[1] = tab[5];
	data->spheres[i].color.rgb[2] = tab[6];
	i++;
	return (1);
}

void	fill_struct_L(t_data *data, double tab[])
{
	int i;

	i = 0;
	// printf("L:\n");
	// while (tab[i] != 1024)
	// {
	// 	if (i == 0)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 1)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 2)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 3)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 4)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 5)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 6)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	i++;
	// }
}

int	create_and_fill_struct_cy(t_data *data, double tab[])
{
	int i;

	i = 0;
	// printf("cy:\n");
	// while (tab[i] != 1024)
	// {
	// 	if (i == 0)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 1)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 2)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 3)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 4)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 5)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 6)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 7)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 8)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 9)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 10)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	i++;
	// }
	return (1);
}

int	create_and_fill_struct_pl(t_data *data, double tab[])
{
	int i;

	i = 0;
	// printf("pl:\n");
	// while (tab[i] != 1024)
	// {
	// 	if (i == 0)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 1)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 2)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 3)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 4)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 5)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 6)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 7)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	if (i == 8)
	// 		printf("%i: %f\n", i, tab[i]);
	// 	i++;
	// }
	return (1);
}




void	print_tab(double tab[], char *str)
{
	int	i;

	printf("%s", str);
	i = 0;
	while (tab[i] != 1024)
		printf("%f\n", tab[i++]);
}