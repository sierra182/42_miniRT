#include "get_sphere_color_bonus.h"

int	calculate_spotlight_effect3(t_spotlight *spotlight, t_calc_spotlight_effect_params *params);
void	compute_light_ray(t_spotlight *spotlight, t_get_color_params *params,
	t_ray_pack *light_ray);
/**========================================================================
 *                           COMPUTE_SPHERE_NORMAL
 *========================================================================**/
static void	compute_sph_normal(t_get_color_params *params,
	t_sphere *sphere, t_ray_vector *normal, t_ray_pack *light_ray)
{
	get_intersect_point(params->ray, params->t, &light_ray->ray.origin_vect);
	subtract_vector(light_ray->ray.origin_vect.axis,
		sphere->origin_vect.axis, normal->axis);
	self_normalize_vector(normal->axis);
	if (sphere->which_t == 2)
		symmetrize_vector(normal->axis);
}

/**========================================================================
 *                         ADD_SPH_SPOTLIGHTS_EFFECT
 *========================================================================**/
static void	add_sph_spotlights_effect(t_get_color_params *params,
	t_ray_vector *normal, t_color *spotlighties_color, t_color *mesh_color, t_ray_pack	*light_ray)
{
	t_color	spotlighty_color;
	int		i;

	*spotlighties_color = (t_color){.rgb[0] = 0, .rgb[1] = 0, .rgb[2] = 0};
	i = -1;
	while (++i < params->data->sl_nbr)
	{
		compute_light_ray(&params->data->spotlights[i], params,
			light_ray);
		if (is_sphere_surface_between(params->mesh->ref,
				&params->data->spotlights[i])
			|| (has_shadow(params->data, params->mesh, light_ray)
				&& scalar_product(light_ray->ray.dir_vect.axis,
					normal->axis) > 0))
			continue ;
		calculate_spotlight_effect3(&params->data->spotlights[i],
			&(t_calc_spotlight_effect_params)
		{params, mesh_color, normal, &spotlighty_color, light_ray});
		add_color(spotlighties_color, &spotlighty_color, spotlighties_color);
	}
}

/**========================================================================
 *                           GET_SPHERE_COLOR
 *========================================================================**/
int	get_sphere_color(t_get_color_params *params)
{
	t_ray_vector	normal;
	t_ray_pack		light_ray;
	t_color			ambiantly_color;
	t_color			spotlighties_color;
	t_sphere		*sphere;

	sphere = (t_sphere *) params->mesh->ref;
	compute_sph_normal(params, sphere, &normal, &light_ray);
	calculate_ambiant_effect(params, &sphere->color, &normal,
		&ambiantly_color);
	add_sph_spotlights_effect(params, &normal, &spotlighties_color,
		&sphere->color, &light_ray);
	add_color(&spotlighties_color, &ambiantly_color, params->color);
	apply_aces_tonemap(params->color);
	return (0);
}