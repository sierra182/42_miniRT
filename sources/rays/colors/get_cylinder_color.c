#include "get_cylinder_color.h"

/**========================================================================
 *                           HANDLE_PROJECTION
 *========================================================================**/
void	handle_projection(t_get_color_params *params, t_ray_vector *normal,
	t_ray *light_ray)
{
	t_ray_vector	intersect_point;
	t_ray_vector	cyl_to_intersect;
	double			proj;
	t_ray_vector	proj_vect;
	t_cylinder		*cyl;

	cyl = (t_cylinder *)params->mesh->ref;
	get_intersect_point(params->ray, params->t, &intersect_point);
	subtract_vector(intersect_point.axis, cyl->origin_vect.axis,
		cyl_to_intersect.axis);
	proj = scalar_product(cyl_to_intersect.axis, cyl->axis_vect.axis);
	scale_vector(cyl->axis_vect.axis, proj, proj_vect.axis);
	subtract_vector(cyl_to_intersect.axis, proj_vect.axis, normal->axis);
	self_normalize_vector(normal->axis);
	if (cyl->which_t == 2)
		symmetrize_vector(normal->axis);
	light_ray->origin_vect = intersect_point;
}

/**========================================================================
 *                           GET_CYLINDER_COLOR_CYL
 *========================================================================**/
int	get_cylinder_color_cyl(t_get_color_params *params)
{
	t_ray_pack		light_ray;
	t_color			ambiantly_color;
	t_cylinder		*cyl;
	t_color			spotlighty_color;
	t_ray_vector	tmp;

	cyl = (t_cylinder *)params->mesh->ref;
	handle_projection(params, params->normal, &light_ray.ray);
	subtract_vector(params->data->spotlight.origin_vect.axis, light_ray.
		ray.origin_vect.axis, light_ray.ray.dir_vect.axis);
	calculate_ray_pack(&light_ray);
	cast_vector_mat_ray(&cyl->axis_vect, &tmp);
	self_normalize_vector(tmp.axis);
	calculate_ambiant_effect(params, &cyl->color, params->normal,
		&ambiantly_color);
	if (has_shadow(params->data, params->normal, params->mesh, &light_ray)
		|| is_cylinder_surface_between (cyl, params->normal, params->data
			->spotlight.origin_vect.axis) || (!is_in_cyl_height(&tmp, cyl,
				params->data->spotlight.origin_vect.axis)
			&& (cyl->which_t == 2)))
		return (*params->color = ambiantly_color,
			apply_aces_tonemap(params->color), 0);			
	calculate_spotlight_effect(&(t_calc_spotlight_effect_params)
	{params, &cyl->color, params->normal, &spotlighty_color, &light_ray});
	add_color(&spotlighty_color, &ambiantly_color, params->color);
	apply_aces_tonemap(params->color);
	return (0);
}

/**========================================================================
 *                           GET_CYLINDER_COLOR
 *========================================================================**/
void	get_cylinder_color(t_data *data, t_ray *ray, t_obj *obj,
		t_color *color)
{
	t_ray_vector	normal;
	t_cylinder		*cyl;

	cyl = (t_cylinder *)obj->ref;
	if (cyl->cyl_or_discs == cylinder)
	{
		get_cylinder_color_cyl(&(t_get_color_params)
		{data, ray, obj->t, obj, color, &normal});
	}
	if (cyl->cyl_or_discs == discs)
	{
		get_cylinder_color_discs(&(t_get_color_params)
		{data, ray, obj->t, obj, color, &normal});
	}
}
