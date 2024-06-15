#include "ray_utils_bonus.h"

/**========================================================================
 *                           IS_BEHIND_CAM
 *========================================================================**/
int	is_behind_cam(double t)
{
	return (t <= 0.0);
}

/**========================================================================
 *                           GET_INTERSECT_POINT
 *========================================================================**/
void	get_intersect_point(t_ray *ray, double t, t_ray_vector *inter_pt)
{
	t_ray_vector	scaled_vect;

	scale_vector(ray->dir_vect.axis, t, scaled_vect.axis);
	add_vector(ray->origin_vect.axis, scaled_vect.axis, inter_pt->axis);
}

/**========================================================================
 *                           GET_LOCAL_INTERSECT_POINT
 *========================================================================**/
void	get_local_intersect_point(t_ray *ray, double t, t_ray_vector *inter_pt)
{
	scale_vector(ray->dir_vect.axis, t, inter_pt->axis);
}

/**========================================================================
 *                           COMPUTE_LIGHT_RAY
 *========================================================================**/
void	compute_light_ray(t_spotlight *spotlight, t_get_color_params *params,
	t_ray_pack *light_ray)
{
	subtract_vector(spotlight->origin_vect.axis,
		light_ray->ray.origin_vect.axis, light_ray->ray.dir_vect.axis);
	light_ray->ray_norm.origin_vect = light_ray->ray.origin_vect;
	light_ray->magnitude = get_vector_magnitude(light_ray->ray.dir_vect.axis);
	normalize_vector(light_ray->ray.dir_vect.axis, light_ray->magnitude,
		light_ray->ray_norm.dir_vect.axis);
}
