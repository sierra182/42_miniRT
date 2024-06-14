#include "event_bonus.h"

/**========================================================================
 *                           ASSIGN_VECTOR
 *========================================================================**/
void	assign_vector(t_matrix_vector *origin_vect, t_matrix_vector *dir_vect,
	t_matrix_vector **new_origin_vect, t_matrix_vector **new_dir_vect)
{
	*new_origin_vect = origin_vect;
	*new_dir_vect = dir_vect;
}

/**========================================================================
 *                           HANDLE_MESH_COLOR_UPDATE
 *========================================================================**/
void	handle_mesh_color_update(t_data *data, t_obj *mesh)
{
	int		i;
	t_color	*color;

	color = NULL;
	if (mesh->type == O_SP)
		color = &((t_sphere *) mesh->ref)->color;
	else if (mesh->type == O_CY)
		color = &((t_cylinder *) mesh->ref)->color;
	else if (mesh->type == O_PL)
		color = &((t_plane *) mesh->ref)->color;
	if (color)
	{
		data->event.color_sav = *color;
		i = -1;
		while (++i < AXIS)
			color->rgb[i] += 100;
		clamp_255(color);
	}
	data->event.actual_mesh = *mesh;
}

/**========================================================================
 *                           ACTUAL_MESH_HANDLE
 *========================================================================**/
void	actual_mesh_handle(t_data *data, t_obj *mesh,
	t_matrix_vector **origin_vect, t_matrix_vector **dir_vect)
{
	if (mesh)
		handle_mesh_color_update(data, mesh);
	else if (data->event.actual_mesh.ref)
	{
		if (data->event.actual_mesh.type == O_SP)
			assign_vector(&((t_sphere *) data->event.actual_mesh.ref)
				->origin_vect, NULL, origin_vect, dir_vect);
		else if (data->event.actual_mesh.type == O_PL)
			assign_vector(&((t_plane *) data->event.actual_mesh.ref)
				->origin_vect, &((t_plane *) data->event.actual_mesh.ref)
				->norm_vect, origin_vect, dir_vect);
		else if (data->event.actual_mesh.type == O_CY)
			assign_vector(&((t_cylinder *) data->event.actual_mesh.ref)
				->origin_vect, &((t_cylinder *)data->event.actual_mesh.ref)
				->axis_vect, origin_vect, dir_vect);
	}
}

/**========================================================================
 *                           EVENT_INTENSITY
 *========================================================================**/
void	event_intensity(int keycode, double *intensity)
{
	if (keycode == PLUS && *intensity <= 0.9)
		*intensity += 0.1;
	else if (keycode == MINUS && *intensity >= 0.1)
		*intensity -= 0.1;
}

double	is_intersect_sphere(t_ray *ray, void *input_sphere, t_ray_vector *i);

static double	has_bulb(t_data *data, t_ray *ray)
{
	double	inter_bulb;
	int		i;

	i = -1;
	while (++i < data->sl_nbr)
	{
		inter_bulb = is_intersect_sphere(ray, &data->spotlights[i].bulb, NULL);
		if (inter_bulb)
		{
			data->event.actual_light = &data->spotlights[i];			
			return (inter_bulb);
		}	
	}
	return (0.0);	
}
int	is_behind_cam(double t);//


/**========================================================================
 *                           EVENT_LAUNCH_RAYS
 *========================================================================**/
void	event_launch_rays(t_data *data, int x, int y)
{
	t_ray	ray;
	t_obj	obj;

	obj.ref = NULL;
	obj.t = 100000000;
	new_ray(&data->cam, &ray, x, y);
	get_closest_intersection_sp(data, &ray, &obj);
	get_closest_intersection_cy(data, &ray, &obj);
	get_closest_intersection_pl(data, &ray, &obj);
	if (obj.ref && !is_behind_cam(obj.t))//!modif mandat
		actual_mesh_handle(data, &obj, NULL, NULL);
}

void	actual_light_handle(t_data *data, int store_color,
	t_matrix_vector **origin_vect)
{
	if (store_color)
		;//!handle_mesh_color_update(data, mesh);
	else if (data->event.actual_light)
		*origin_vect = &data->event.actual_light->origin_vect;	
}

void	event_spotlight_launch_rays(t_data *data, int x, int y)
{
	t_ray		ray;
	
	new_ray(&data->cam, &ray, x, y);
	if (!is_behind_cam(has_bulb(data, &ray)))
		actual_light_handle(data, 1, NULL);
}
