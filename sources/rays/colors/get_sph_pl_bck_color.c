/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sph_pl_bck_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:04:09 by svidot            #+#    #+#             */
/*   Updated: 2024/06/26 14:04:10 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_sph_pl_bck_color.h"

/**========================================================================
 *                           COMPUTE_SPHERE_NORMAL_AND_LIGHT_RAY
 *========================================================================**/
void	compute_sph_normal_and_light_ray(t_get_color_params *params,
	t_sphere *sphere, t_ray_vector *normal, t_ray_pack *light_ray)
{
	get_intersect_point(params->ray, params->t, &light_ray->ray.origin_vect);
	subtract_vector(params->data->spotlight.origin_vect.axis,
		light_ray->ray.origin_vect.axis, light_ray->ray.dir_vect.axis);
	calculate_ray_pack(light_ray);
	subtract_vector(light_ray->ray.origin_vect.axis,
		sphere->origin_vect.axis, normal->axis);
	self_normalize_vector(normal->axis);
	if (sphere->which_t == 2)
		symmetrize_vector(normal->axis);
}

/**========================================================================
 *                           GET_SPHERE_COLOR
 *========================================================================**/
int	get_sphere_color(t_get_color_params *params)
{
	t_ray_vector	normal;
	t_ray_pack		light_ray;
	t_color			ambiantly_color;
	t_color			spotlighty_color;
	t_sphere		*sphere;

	sphere = (t_sphere *) params->mesh->ref;
	compute_sph_normal_and_light_ray(params, sphere, &normal, &light_ray);
	calculate_ambiant_effect(params, &sphere->color, &normal,
		&ambiantly_color);
	if (is_sphere_surface_between(params->mesh->ref, &params->data->spotlight)
		|| (has_shadow(params->data, params->mesh, &light_ray)
			&& scalar_product(light_ray.ray.dir_vect.axis, normal.axis) > 0))
	{
		*params->color = ambiantly_color;
		apply_aces_tonemap(params->color);
		return (0);
	}
	calculate_spotlight_effect(&(t_calc_spotlight_effect_params)
	{params, &sphere->color, &normal, &spotlighty_color, &light_ray});
	add_color(&spotlighty_color, &ambiantly_color, params->color);
	apply_aces_tonemap(params->color);
	return (0);
}

/**========================================================================
 *                           COMPUTE_PL_NORMAL_AND_LIGHT_RAY
 *========================================================================**/
void	compute_pl_normal_and_light_ray(t_get_color_params *params,
	t_plane *plane, t_ray_vector *normal, t_ray_pack *light_ray)
{
	double	view_dot_normal;

	cast_vector_mat_ray(&plane->norm_vect, normal);
	self_normalize_vector(normal->axis);
	get_intersect_point(params->ray, params->t, &light_ray->ray.origin_vect);
	subtract_vector(params->data->spotlight.origin_vect.axis,
		light_ray->ray.origin_vect.axis, light_ray->ray.dir_vect.axis);
	calculate_ray_pack(light_ray);
	view_dot_normal = scalar_product(normal->axis, params->ray->dir_vect.axis);
	if (view_dot_normal > 0)
		symmetrize_vector(normal->axis);
}

/**========================================================================
 *                           GET_PLANE_COLOR
 *========================================================================**/
int	get_plane_color(t_get_color_params *params)
{
	t_ray_vector	normal;
	t_ray_pack		light_ray;
	t_color			ambiantly_color;
	t_color			spotlighty_color;
	t_plane			*plane;

	plane = ((t_plane *) params->mesh->ref);
	compute_pl_normal_and_light_ray(params, plane, &normal, &light_ray);
	calculate_ambiant_effect(params, &plane->color, &normal, &ambiantly_color);
	if (has_shadow(params->data, params->mesh, &light_ray)
		|| scalar_product(normal.axis, light_ray.ray.dir_vect.axis) < 1e-3)
	{
		*params->color = ambiantly_color;
		apply_aces_tonemap(params->color);
		return (0);
	}
	calculate_spotlight_effect(&(t_calc_spotlight_effect_params)
	{params, &plane->color, &normal, &spotlighty_color, &light_ray});
	add_color(&spotlighty_color, &ambiantly_color, params->color);
	apply_aces_tonemap(params->color);
	return (0);
}

/**========================================================================
 *                           GET_BACKGROUND_COLOR
 *========================================================================**/
int	get_background_color(t_ray *ray, t_data *data)
{
	int		color[2];
	int		rgb[3];
	double	dir;
	t_color	*bg_color;
	double	intensity;

	intensity = data->ambiant_light.intensity;
	bg_color = (t_color *)&data->ambiant_light.color;
	dir = (ray->dir_vect.axis[1] + 1.0) * 0.5;
	color[0] = get_color(intensity * 255, intensity * 255, intensity * 255);
	color[1] = get_color(bg_color->rgb[0] * intensity, bg_color->rgb[1]
			* intensity, bg_color->rgb[2] * intensity);
	rgb[0] = (int)((1.0 - dir) * ((color[1] >> 16) & 0xFF) + dir
			* ((color[0] >> 16) & 0xFF));
	rgb[1] = (int)((1.0 - dir) * ((color[1] >> 8) & 0xFF) + dir
			* ((color[0] >> 8) & 0xFF));
	rgb[2] = (int)((1.0 - dir) * (color[1] & 0xFF) + dir * (color[0] & 0xFF));
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
