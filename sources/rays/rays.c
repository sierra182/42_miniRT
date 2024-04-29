#include "rays.h"

static void	normalize_vector(t_vector *vector)
{
	int		i;
	double	magnitude;

	magnitude = sqrt(pow(vector->axis[0], 2) + pow(vector->axis[1], 2)
			+ pow(vector->axis[2], 2));
	i = -1;
	while (++i < AXIS)
		vector->axis[i] /= magnitude;
}

static double	normalize_pixel(int screen_size, int pixel, int x_flag)
{
	if (x_flag)
		return (((pixel + 0.5) / screen_size) * 2 - 1);
	return ((1 - 2 * (pixel + 0.5) / screen_size));
}

static void	new_ray(t_cam *cam, int x, int y, t_ray *ray)
{
	double		norm_scale_x;
	double		norm_scale_y;

	ray->origin_vect = cam->origin_vect;
	norm_scale_y = normalize_pixel(cam->resol[1], y, 0) * cam->scale;
	norm_scale_x = normalize_pixel(cam->resol[0], x, 1) * cam->scale
		* cam->aspect;
	scale_and_add_vectors(cam, ray, norm_scale_x, norm_scale_y);
	normalize_vector(&ray->dir_vect);
}

void	launch_rays(t_cam *cam)
{
	t_ray	ray;
	double	aspect;
	double	scale;
	int		x;
	int		y;

	cam->scale = tan(cam->fov / 2);
	cam->aspect = cam->resol[0] / cam->resol[1];
	y = -1;
	while (++y < cam->resol[1])
	{
		x = -1;
		while (++x < cam->resol[0])
			new_ray(cam, x, y, &ray);
	}
}
